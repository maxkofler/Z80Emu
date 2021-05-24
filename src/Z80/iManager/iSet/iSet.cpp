#include "iSet.h"

ISet::ISet(Z80* z80){
    FUN();
    this->z80 = z80;
    this->mainIS = new MainIS(this->z80);
    this->bitIS = new BitIS(this->z80);


    this->opBytes = new uint8_t[256] {
        0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,     //0x00
        1, 2, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0,     //0x10
        1, 2, 2, 0, 0, 0, 1, 0, 1, 0, 2, 0, 0, 0, 1, 0,     //0x20
        1, 2, 2, 0, 0, 0, 1, 0, 1, 0, 2, 0, 0, 0, 1, 0,     //0x30

        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     //0x40
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     //0x50
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     //0x60
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     //0x70

        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     //0x80
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     //0x90
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     //0xA0
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     //0xB0

        0, 0, 2, 2, 2, 0, 1, 0, 0, 0, 2, 0, 2, 2, 1, 0,     //0xC0
        0, 0, 2, 1, 2, 0, 1, 0, 0, 0, 2, 1, 2, 0, 1, 0,     //0xD0
        0, 0, 2, 0, 2, 0, 1, 0, 0, 0, 2, 0, 2, 0, 1, 0,     //0xE0
        0, 0, 2, 0, 2, 0, 1, 0, 0, 0, 2, 0, 2, 0, 1, 0      //0xF0
    };
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

void ISet::execIS(uint8_t* is){
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