#include "util.h"

#include <unistd.h>

void enter_no_echo(struct no_echo_state* state)
{
    tcgetattr(STDIN_FILENO, &state->old_tattr);

    struct termios new_tattr = state->old_tattr;
    new_tattr.c_lflag &= ~(ECHO|ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tattr);
}

void exit_no_echo(struct no_echo_state* state)
{
    tcsetattr(STDIN_FILENO, TCSANOW, &state->old_tattr);
}