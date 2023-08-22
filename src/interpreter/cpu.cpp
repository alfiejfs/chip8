#include <interpreter/cpu.h>

#include <algorithm>

constexpr byte FONT_VALUES[] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

CPU::CPU()
: d_memory()
, d_programCounter()
, d_indexRegister()
, d_stack()
, d_delayTimer()
, d_soundTimer()
, d_registers({0}) // zeros out the array
{

}

CPU::~CPU()
{

}

/* Performs an iteration of the FDE cycle */
void CPU::perform_cycle() 
{
    instruction instruction = fetch();
    decode_and_execute(instruction);
}

instruction CPU::fetch() 
{
    byte first_byte = d_memory[d_programCounter];
    byte second_byte = d_memory[d_programCounter + 1];

    // Combining the bytes to form a full instruction
    instruction instruction = (first_byte << 8) | second_byte; 

    // Program counter must be incremented by 2 as 2 bytes were read
    d_programCounter += 2;

    return instruction;
}

void CPU::decode_and_execute(instruction& instruction)
{
    byte first_nibble = instruction >> 12;
    byte second_nibble = (instruction >> 8) & 0b1111;
    byte third_nibble = (instruction >> 4) & 0b1111;
    byte fourth_nibble = instruction & 0b1111;
    byte second_byte = instruction >> 8;
    word tail_nibbles = instruction & (1 << 12); 

    
}

/*
 * The font is written from 0x50 to 0x9F
*/
void CPU::write_font() 
{
    std::copy(std::begin(FONT_VALUES), std::end(FONT_VALUES), std::begin(d_memory) + 0x50);
}