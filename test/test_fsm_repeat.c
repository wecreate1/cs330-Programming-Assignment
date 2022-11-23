#include "test_utils.h"
#include "security-device.h"

int main(int argc, char** argv)
{
    struct passcodes passcodes = {L"12301245", L'6', L'8'};
    struct fsm fsm;
    fsm_init(&fsm, &passcodes);

    ASSERT(fsm_transition(&fsm, L'1') == NOTHING);
    ASSERT(fsm_transition(&fsm, L'2') == NOTHING);
    ASSERT(fsm_transition(&fsm, L'3') == NOTHING);
    ASSERT(fsm_transition(&fsm, L'0') == NOTHING);
    ASSERT(fsm_transition(&fsm, L'1') == NOTHING);
    ASSERT(fsm_transition(&fsm, L'2') == NOTHING);
    ASSERT(fsm_transition(&fsm, L'3') == NOTHING);
    ASSERT(fsm_transition(&fsm, L'0') == NOTHING);
    ASSERT(fsm_transition(&fsm, L'1') == NOTHING);
    ASSERT(fsm_transition(&fsm, L'2') == NOTHING);
    ASSERT(fsm_transition(&fsm, L'4') == NOTHING);
    ASSERT(fsm_transition(&fsm, L'5') == NOTHING);
    ASSERT(fsm_transition(&fsm, L'6') == UNLOCK);

    SUCCEED();

    return 0;
}