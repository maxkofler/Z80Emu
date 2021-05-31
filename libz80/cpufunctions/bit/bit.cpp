#include "cpufunctions/bit.h"

Bit::Bit(Z80* z80){
    this->z80 = z80;
}

void Bit::bit(uint8_t pos, uint8_t reg){
    //Flags:    N(r), H(s), Z(d)
    bool r = (reg >> pos) & 1;
    z80->NF(false);
    z80->HF(true);
    z80->ZF(!r);
}
void Bit::bit(uint8_t pos, uint16_t reg){
    bool r = (reg >> pos) & 1;
    z80->NF(false);
    z80->HF(true);
    z80->ZF(!r);
}

uint8_t Bit::res(uint8_t pos, uint8_t reg){
    //No flags affected
    return reg &= ~(1 << pos);
}
uint16_t Bit::res(uint8_t pos, uint16_t reg){
    //No flags affected
    return reg &= ~(1 << pos);
}

uint8_t Bit::set(uint8_t pos, uint8_t reg){
    //No flags affected
    return reg |= (1 << pos);
}
uint16_t Bit::set(uint8_t pos, uint16_t reg){
    //No flags affected
    return reg |= (1 << pos);
}