#include <iostream>
#include <fstream>
#include <vector>
#include "disassembler.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <chip8_program.ch8>" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1], std::ios::binary);
    if (!inputFile) {
        std::cerr << "Error: Unable to open file " << argv[1] << std::endl;
        return 1;
    }

    // Read the binary file into a buffer
    std::vector<uint8_t> buffer((std::istreambuf_iterator<char>(inputFile)),
                                std::istreambuf_iterator<char>());
    inputFile.close();

    // Initialize the disassembler and process the buffer
    Disassembler disassembler;
    disassembler.disassemble(buffer);

    return 0;
}
