#include <locale.h>
#include <wchar.h>
#include <stdlib.h>

#include "security-device.h"

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");
    struct passcodes passcodes = {L"10340", L'1', L'4'};

    struct fsm fsm;
    fsm_init(&fsm, &passcodes);

    enum action action;

    wint_t c;

    long long successes = 0;
    long long attempts = 0;

    wprintf(L"successes\\attempts\t{attempts/successes}\n");

    while (1) {
        // for (int i = 0; i < 5; i++) {
        //     c = (rand() % 10) + L'0';
        //     fsm_transition(&fsm, c);
        // }
        do {
            c = (rand() % 10) + L'0';
            action = fsm_transition(&fsm, c);
            attempts++;
            
        } while (action != UNLOCK);
        successes++;
        if ((int)successes%10 == 0)
            wprintf(L"%lld\\%lld: \t%d\n", successes, attempts, attempts/successes);
    }
}