#include "rotate.h"

Rotate::Rotate(Z80* z80){
    this->z80 = z80;
}

uint8_t Rotate::RLC(uint8_t reg){
    //Flags: N & H - reset, C
    this->z80->NF(false);
    this->z80->HF(false);
    this->z80->CF(reg >> 7);
    return reg << 1;
}