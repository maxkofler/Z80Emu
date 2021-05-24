#include "iSet.h"

Instruction ISet::fetchInstruction(uint8_t opcode){
    FUN();

    Instruction newInstruction;
    newInstruction.addByte(opcode);

    switch(opcode){
        
        default:
            LOGI("Using main instruction set");
            this->mainIS->fetch(newInstruction);
            break;
    }

    return newInstruction;
}