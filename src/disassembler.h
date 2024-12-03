#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H

#include <cstdint>
#include <string>
#include <vector>

#include <fstream>
#include <iostream>


// load ROM file into vector of 2-byte (16 bit) opcodes
std::vector<uint16_t> loadROM(const std::string& romPath);

// disassemble an opcode into a string description
std::string disassembleOpcode(uint16_t opcode);

// disassemble a list of opcodes
std::vector<std::string> disassembleList(const std::vector<uint16_t>& opcodes);

#endif