#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

class Z80EmuInstrucion;

#include "log.h"

#include <vector>

class Z80EmuInstrucion{
public:
    uint8_t                     &operator[](size_t i);

    void                        addByte(uint8_t byte);

    uint8_t                     getLastByte();

    void                        setCycles(uint8_t c){this->_cycles = c;}

    uint8_t                     getCycles(){return this->_cycles;}

    size_t                      size(){return this->_instruction.size();}
private:
    std::vector<uint8_t>        _instruction;
    uint8_t                     _cycles;
};

#endif