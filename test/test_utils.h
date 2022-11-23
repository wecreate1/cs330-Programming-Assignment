#ifndef CS330_TEST_UTILS_H
#define CS330_TEST_UTILS_H

#include <stdlib.h>
#include <wchar.h>

#define TEST_FAIL 1
#define TEST_SUCCESS 0

#define SUCCEED() exit(TEST_SUCCESS);

#define ASSERT(x_) {if (!(x_)) {exit(TEST_FAIL);}};

extern struct passcodes passcodes1;

#define PASSCODE1_NEITHER_ACTION L'8'

extern struct passcodes passcodes2;
extern struct passcodes passcodes3;

extern wchar_t* non_digit_garble;

#endif