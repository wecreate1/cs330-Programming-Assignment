
#include <wchar.h>
#include <wctype.h>

#include "security-device.h"

#ifndef __STDC_ISO_10646__
#ifndef IGNORE___STDC_ISO_10646__
#error "wchar_t should be unicode, support not guranteed"
#error "Ignore by defining IGNORE___STDC_ISO_10646__"
#endif
#endif

#define WEOT L'\x04'

static inline wchar_t fsm_expected_input(struct fsm* fsm)
{
    return fsm->passcodes->access_code[fsm->state.i];
}

void fsm_init(struct fsm* fsm, const struct passcodes* passcodes)
{
    fsm->passcodes = passcodes;
    fsm->state.access_state = NO_ACCESS;
    fsm->state.i = 0;
}

// Used in case the access code contains part of itself (e.g. 12123 contains the code 1213 but would fail without this mess)
static void fsm_backtrack(struct fsm* fsm, wchar_t input)
{
    for (int i = 0; i < fsm->state.i; i++) {
        int j;
        for (j = 0; j < fsm->state.i - i; j++) {
            if (fsm->passcodes->access_code[j] != fsm->passcodes->access_code[i+j]) {
                break;
            }
        }
        if (j == fsm->state.i-i && fsm->passcodes->access_code[j] == input) {
            fsm->state.i = j+1;
            return;
        }
    }
    if (fsm->passcodes->access_code[0] == input) {
        fsm->state.i = 1;
        return;
    }
    fsm->state.i = 0;
    return;
}

enum action fsm_transition(struct fsm* fsm, wchar_t input)
{
    if (iswdigit(input)) {
        switch (fsm->state.access_state)
        {
        case NO_ACCESS:
            if (fsm_expected_input(fsm) == input) {
                fsm->state.i++;
                if (fsm_expected_input(fsm) == L'\0') {
                    fsm->state.access_state = ACCESS_GRANTED;
                }
            } else {
                fsm_backtrack(fsm, input);
            }
            return NOTHING;
            break;
        case ACCESS_GRANTED:
            fsm->state.access_state = NO_ACCESS;
            if (input == fsm->passcodes->unlock_char) {
                fsm->state.i = 0;
                return UNLOCK;
            } else if (input == fsm->passcodes->lock_char) {
                fsm->state.i = 0;
                return LOCK;
            } else {
                fsm_backtrack(fsm, input);
            }
            break;
        }
    } else if (input == WEOT) {
        return TERMINATE;
    }
    return NOTHING;
}
