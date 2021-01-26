#include "iSet.h"

ISet::ISet(Z80* z80, Log* log){
    this->z80 = z80;
    this->log = log;
    this->mainIS = new MainIS(this->z80, this->log);
    this->bitIS = new BitIS(this->z80, this->log);


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
    //0xCB  bit instructions
    //0xDD  IX  instructions
    //0xED  EXT instructions
    //0xFD  IY  instructions

    if (opcode == 0xCB){
        log->log("ISet::getOPBytes()", "Switching to BIT instructions (1 additional byte as operand)", Log::D3);
        return 1;
    }
    else if (opcode == 0xDD){
        log->log("ISet::getOPBytes()", "Switching to IX instructions (not included yet!)", Log::D3);
        return 0;
    }
    else if (opcode == 0xED){
        log->log("ISet::getOPBytes()", "Switching to EXT instructions (not included yet!)", Log::D3);
        return 0;
    }
    else if (opcode == 0xFD){
        log->log("ISet::getOPBytes()", "Switching to IY instructions (not included yet!)", Log::D3);
        return 0;
    }
    else{
        log->log("Iset::getOPBytes()", "Using main instruction set!", Log::D3);
        return this->opBytes[opcode];
    }
    
}

void ISet::execIS(uint8_t* is){

    if (is[0] == 0xCB){
        log->log("ISet::execIS()", "Executing instruction from Bit instruction set!", Log::D3);
        this->bitIS->exec(is[1]);
    }
    else{
        log->log("ISet::execIS()", "Executing instruction from Main instruction set!", Log::D3);
        this->mainIS->exec(is);
    }
}

uint8_t ISet::getISCycles(uint8_t opcode){
    if (opcode == 0xCB){
        log->log("ISet::getISCycles()", "Getting instruction cycles from Bit instruction set (" + Log::toHexString(opcode) + ")", Log::D3);
        return this->bitIS->getCycles(opcode);
    }
    else{
        log->log("ISet::getISCycles()", "Getting instruction cycles from Main instruction set (" + Log::toHexString(opcode) + ")", Log::D3);
        return this->mainIS->getCycles(opcode);
    }
}