#include "instructions/mainIs.h"

void MainIS::fetch(Z80EmuInstrucion& instruction){
    FUN();
    
    for (uint8_t i = 0; i < this->_opBytes[instruction[0]]; i++){
        instruction.addByte(z->readFromPCInc());
    }

    instruction.setCycles(this->_opCycles[instruction[0]]);
}