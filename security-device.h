#ifndef CS330_SECURITY_DEVICE_H
#define CS330_SECURITY_DEVICE_H

#include <wchar.h>

struct passcodes
{
    wchar_t* access_code;
    wchar_t unlock_char;
    wchar_t lock_char;
};

enum access_state
{
    NO_ACCESS,
    ACCESS_GRANTED
};

struct fsm_state
{
    enum access_state access_state;
    int i;
};

struct fsm {
    const struct passcodes* passcodes;
    struct fsm_state state;
};

enum action
{
    NOTHING,
    UNLOCK,
    LOCK,
    TERMINATE
};

void fsm_init(struct fsm* fsm, const struct passcodes* passcodes);
enum action fsm_transition(struct fsm* fsm, wchar_t input);

#endif