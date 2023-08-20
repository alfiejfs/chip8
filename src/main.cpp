#include <iostream>

#include <interpreter/cpu.h>

int main() {

    std::cout << "Initialising CPU." << std::endl;
    CPU cpu;

    std::cout << "CPU initialised. First memory value: " << cpu.d_memory[0] << std::endl;
    
    return 0;
}