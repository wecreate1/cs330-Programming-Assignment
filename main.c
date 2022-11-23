#include <locale.h>
#include <wchar.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>

#include "security-device.h"
#include "util.h"

struct no_echo_state term_state;

static void sigint_handler(int sig)
{
    exit_no_echo(&term_state);
    _exit(0);
}

static void setup_sigint(void)
{
    struct sigaction act = {};
    act.sa_handler = sigint_handler;
    sigemptyset(&act.sa_mask);
    
    sigaction(SIGINT, &act, NULL);
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");

    struct passcodes passcodes = {L"10340", L'1', L'4'};

    enter_no_echo(&term_state);
    setup_sigint();

    struct fsm fsm;
    fsm_init(&fsm, &passcodes);

    wint_t c;

    while ((c = getwchar()) != WEOF)
    {
        enum action action = fsm_transition(&fsm, c);

        if (action == NOTHING) {

        } else if (action == UNLOCK) {
            wprintf(L"Unlocked!\n");
        } else if (action == LOCK) {
            wprintf(L"Locked!\n");
        } else if (action == TERMINATE) {
            break;
        }
    }

    exit_no_echo(&term_state);
}