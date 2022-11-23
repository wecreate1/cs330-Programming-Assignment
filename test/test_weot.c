#include <stdlib.h>

#include "test_utils.h"
#include "security-device.h"

int main(int argc, char** argv)
{
    struct fsm fsm;
    fsm_init(&fsm, &passcodes1);

    for (int i = 0; i < 3; i++) {
        ASSERT(fsm_transition(&fsm, passcodes1.access_code[i]) == NOTHING);
    }

    ASSERT(fsm_transition(&fsm, L'\x04') == TERMINATE);

    SUCCEED();

    return 0;
}