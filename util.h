#ifndef CS330_UTIL_H
#define CS330_UTIL_H

#include <termios.h>

struct no_echo_state
{
    struct termios old_tattr;
};

void enter_no_echo(struct no_echo_state* state);
void exit_no_echo(struct no_echo_state* state);

#endif