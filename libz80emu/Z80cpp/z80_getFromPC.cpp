#include "z80emu.h"

uint8_t Z80::readFromPC(){
    FUN();

    return this->mM->get(this->rPC);
}

uint8_t Z80::readFromPCInc(){
    FUN();
    
    uint8_t buf = this->mM->get(this->rPC);
    this->rPC++;
    return buf;
}