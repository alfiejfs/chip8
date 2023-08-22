#ifndef CHIP8_TYPES
#define CHIP8_TYPES

#include <iostream>

typedef unsigned char byte;
typedef unsigned short word;
typedef word instruction;

std::ostream& operator<<(std::ostream& os, const byte& byte);
std::ostream& operator<<(std::ostream& os, const word& word);


#endif