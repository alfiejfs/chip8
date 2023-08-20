#ifndef CHIP8_CPU
#define CHIP8_CPU

#include <common/types.h>

#include <array>

class CPU {

    public:
        CPU();
        ~CPU();

        // Copy constructor not supported
        CPU(const CPU&) = delete;

        // Move constructor not supported
        CPU(const CPU&&) = delete;

        // Copy assignment not supported
        CPU& operator=(const CPU&) = delete;

        // Move assignment not supported
        CPU& operator=(const CPU&&) = delete;      


    public:
        std::array<byte, 4096> d_memory;
};

#endif