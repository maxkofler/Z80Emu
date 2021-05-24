#include "iSet.h"

ISet::ISet(Z80* z80){
    FUN();
    this->z80 = z80;
    this->mainIS = new MainIS(this->z80);
    this->bitIS = new BitIS(this->z80);
}

uint8_t ISet::getOPBytes(uint8_t opcode){
    FUN();
    //0xCB  bit instructions
    //0xDD  IX  instructions
    //0xED  EXT instructions
    //0xFD  IY  instructions

    if (opcode == 0xCB){
        LOGD("Switching to BIT instructions (1 additional byte as operand)");
        return 1;
    }
    else if (opcode == 0xDD){
        LOGD("Switching to IX instructions (not included yet!)");
        return 0;
    }
    else if (opcode == 0xED){
        LOGD("Switching to EXT instructions (not included yet!)");
        return 0;
    }
    else if (opcode == 0xFD){
        LOGD("Switching to IY instructions (not included yet!)");
        return 0;
    }
    else{
        LOGD("Using main instruction set!");
        return this->opBytes[opcode];
    }
    
}

void ISet::execIS(Instruction is){
    FUN();

    if (is[0] == 0xCB){
        LOGD("Executing instruction from Bit instruction set!");
        this->bitIS->exec(is[1]);
    }
    else{
        LOGD("Executing instruction from Main instruction set!");
        this->mainIS->exec(is);
    }
}

uint8_t ISet::getISCycles(uint8_t opcode){
    FUN();
    
    if (opcode == 0xCB){
        LOGD("Getting instruction cycles from Bit instruction set (" + Log::toHexString(opcode) + ")");
        return this->bitIS->getCycles(opcode);
    }
    else{
        LOGD("Getting instruction cycles from Main instruction set (" + Log::toHexString(opcode) + ")");
        return this->mainIS->getCycles(opcode);
    }
}