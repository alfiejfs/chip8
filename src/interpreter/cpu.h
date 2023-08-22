#ifndef CHIP8_CPU
#define CHIP8_CPU

#include <common/types.h>

#include <array>
#include <stack>

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

    // Public functions
    public:
        void perform_cycle();

    // Private functions
    private:
        instruction fetch();

        void decode_and_execute(instruction& instruction);

        void write_font();

    // Members
    private:
        std::array<byte, 4096> d_memory;

        word d_programCounter;

        word d_indexRegister;

        std::stack<word> d_stack;

        byte d_delayTimer;

        byte d_soundTimer;

        byte d_registers[16];

};

#endif