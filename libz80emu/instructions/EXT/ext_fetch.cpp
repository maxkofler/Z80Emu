#include "instructions/extIS.h"

void ExtIS::fetch(Z80EmuInstrucion& is){
    FUN();

    is.addByte(this->z->readFromPCInc());

    uint8_t opcode = is.getLastByte();

    LOGI("Z80EmuInstrucion needs " + std::to_string(this->_opBytes[opcode]) + " operands");

    for (uint8_t i = 0; i < this->_opBytes[opcode]; i++)
        is.addByte(this->z->readFromPCInc());
    
    is.setCycles(this->_opCycles[opcode]);
}