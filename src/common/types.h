#ifndef CHIP8_TYPES
#define CHIP8_TYPES

#include <iostream>

typedef unsigned char byte;

std::ostream& operator<<(std::ostream& os, const byte& byte);

#endif