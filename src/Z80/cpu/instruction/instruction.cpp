#include "instruction.h"

#include <exception>

uint8_t &Instruction::operator[](size_t index){
    if (index < this->_instruction.size())
        return this->_instruction.at(index);
    else{
        LOGE("Accessing out of bounds operand!");
        throw new std::out_of_range("Accessed non-valid index: " + std::to_string(index));
    }
}

void Instruction::addByte(uint8_t byte){
    FUN();

    this->_instruction.push_back(byte);
}

uint8_t Instruction::getLastByte(){
    return this->_instruction.at(this->_instruction.size()-1);
}