#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

class Instruction;

#include "../../log/log.h"

#include <vector>

class Instruction{
public:
    uint8_t                     &operator[](size_t i);

    void                        addByte(uint8_t byte);

    uint8_t                     getLastByte();

    size_t                      size(){return this->_instruction.size();}
private:
    std::vector<uint8_t>        _instruction;
};

#endif