#include "test_utils.h"
#include "security-device.h"

int main(int argc, char** argv)
{
    struct fsm fsm;
    fsm_init(&fsm, &passcodes1);

    fsm.state.access_state = ACCESS_GRANTED;

    ASSERT(fsm_transition(&fsm, passcodes1.unlock_char) == UNLOCK);

    ASSERT(fsm.state.access_state == NO_ACCESS);

    fsm.state.access_state = ACCESS_GRANTED;

    ASSERT(fsm_transition(&fsm, passcodes1.lock_char) == LOCK);

    ASSERT(fsm.state.access_state == NO_ACCESS);

    fsm.state.access_state = ACCESS_GRANTED;

    ASSERT(fsm_transition(&fsm, L'a') == NOTHING);

    ASSERT(fsm.state.access_state == ACCESS_GRANTED);

    fsm.state.access_state = ACCESS_GRANTED;

    ASSERT(fsm_transition(&fsm, PASSCODE1_NEITHER_ACTION) == NOTHING);

    ASSERT(fsm.state.access_state == NO_ACCESS);

    SUCCEED();

    return 0;
}