#include "security-device.h"
#include "test_utils.h"

struct passcodes passcodes1 = {L"12345", L'6', L'7'};

struct passcodes passcodes2 = {L"894589", L'5', L'9'};
struct passcodes passcodes3 = {L"230813", L'3', L'7'};

wchar_t* non_digit_garble = L"akfeybabhkb=-[pavenawk@!&*!%jnafa;[]]";