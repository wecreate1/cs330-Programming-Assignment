#include "test_utils.h"
#include "security-device.h"

int main(int argc, char** argv)
{
    struct passcodes passcodes = {L"12", L'3', L'0'};
    struct fsm fsm;
    fsm_init(&fsm, &passcodes);

    ASSERT(fsm_transition(&fsm, L'1') == NOTHING);
    ASSERT(fsm_transition(&fsm, L'2') == NOTHING);
    ASSERT(fsm_transition(&fsm, L'1') == NOTHING);
    ASSERT(fsm_transition(&fsm, L'2') == NOTHING);
    ASSERT(fsm_transition(&fsm, L'3') == UNLOCK);

    SUCCEED();
    
    return 0;
}