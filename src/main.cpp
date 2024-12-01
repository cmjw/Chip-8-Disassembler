#include "disassembler.h"
#include <iostream>

int main(int argc, char* argv[]) {
    // handle args
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <path to rom>" << std::endl;
        return 1;
    }

    std::string romPath = argv[1];

    try {
        std::vector<uint16_t> opcodes = loadROM(romPath);
    
        std::vector<std::string> instructions = disassembleList(opcodes);

        size_t address = 0x200; // start after reserved area

        for (const auto& instr : instructions) {
            std::cout << std::hex << address << ": " << instr << std::endl;
            address += 2;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}