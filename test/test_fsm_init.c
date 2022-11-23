#include "security-device.h"
#include "test_utils.h"

// #define NULL ((void*) 0)

int main(int argc, char** argv)
{
    struct fsm fsm;
    fsm.passcodes = NULL;
    fsm.state.access_state = ACCESS_GRANTED;
    fsm.state.i = 1;

    fsm_init(&fsm, &passcodes1);

    ASSERT(fsm.passcodes == &passcodes1);
    ASSERT(fsm.state.access_state == NO_ACCESS);
    ASSERT(fsm.state.i == 0);
    
    SUCCEED();

    return 0;
}