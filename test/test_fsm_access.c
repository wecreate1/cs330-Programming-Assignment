#include "test_utils.h"
#include "security-device.h"

int main(int argc, char** argv)
{
    struct fsm fsm;
    fsm_init(&fsm, &passcodes1);

    for (int i = 0; i < 3; i++) {
        ASSERT(fsm_transition(&fsm, passcodes2.access_code[i]) == NOTHING);
        ASSERT(fsm.state.access_state == NO_ACCESS);
    }

    for (int i = 0; i < 3; i++) {
        ASSERT(fsm_transition(&fsm, passcodes1.access_code[i]) == NOTHING);
        ASSERT(fsm.state.access_state == NO_ACCESS);
    }

    wchar_t* c;

    for (c = non_digit_garble; *c != L'\0'; c++) {
        ASSERT(fsm_transition(&fsm, *c) == NOTHING);
        ASSERT(fsm.state.access_state == NO_ACCESS);
    }

    for (c = &passcodes1.access_code[3]; c[1] != L'\0'; c++) {
        ASSERT(fsm_transition(&fsm, *c) == NOTHING);
        ASSERT(fsm.state.access_state == NO_ACCESS);
    }

    ASSERT(fsm_transition(&fsm, *c) == NOTHING);

    ASSERT(fsm.state.access_state == ACCESS_GRANTED);

    for (c = non_digit_garble; *c != L'\0'; c++) {
        ASSERT(fsm_transition(&fsm, *c) == NOTHING);
        ASSERT(fsm.state.access_state = ACCESS_GRANTED);
    }

    ASSERT(fsm_transition(&fsm, PASSCODE1_NEITHER_ACTION) == NOTHING);
    ASSERT(fsm.state.access_state == NO_ACCESS);

    SUCCEED();

    return 0;
}