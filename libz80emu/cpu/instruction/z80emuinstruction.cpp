#include "z80emuinstruction.h"

#include <exception>

uint8_t &Z80EmuInstrucion::operator[](size_t index){
    if (index < this->_instruction.size())
        return this->_instruction.at(index);
    else{
        LOGE("Accessing out of bounds operand!");
        throw new std::out_of_range("Accessed non-valid index: " + std::to_string(index));
    }
}

void Z80EmuInstrucion::addByte(uint8_t byte){
    FUN();

    this->_instruction.push_back(byte);
}

uint8_t Z80EmuInstrucion::getLastByte(){
    return this->_instruction.at(this->_instruction.size()-1);
}