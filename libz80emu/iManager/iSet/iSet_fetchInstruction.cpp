#include "iSet.h"

Instruction ISet::fetchInstruction(uint8_t opcode){
    FUN();

    Instruction newInstruction;
    newInstruction.addByte(opcode);

    switch(opcode){
        case 0xcb:
            LOGI("Fetching using BIT instruction set");
            this->bitIS->fetch(newInstruction);
            break;

        case 0xed:
            LOGI("Fetching using EXT instruction set");
            this->extIS->fetch(newInstruction);
            break;

        default:
            LOGI("Fetching using MAIN instruction set");
            this->mainIS->fetch(newInstruction);
            break;
    }

    return newInstruction;
}