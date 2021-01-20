#include "rotate.h"

Rotate::Rotate(Z80* z80){
    this->z80 = z80;
}

uint8_t Rotate::RLC(uint8_t reg){
    //Flags: N & H - reset, C
    this->z80->NF(false);
    this->z80->HF(false);
    this->z80->CF(reg >> 7);
    return (reg << 1) | (this->z80->CF() << 0);
}

uint8_t Rotate::RL(uint8_t reg){
    //Flags: N & H - reset, C
    bool C;
    uint8_t nreg = reg << 1;
    C = (nreg >> 7);
    nreg = nreg | (this->z80->CF() << 0);
    this->z80->NF(false);
    this->z80->HF(false);
    this->z80->CF(C);
    return nreg;
}


uint8_t Rotate::RRC(uint8_t reg){
    //Flags: N & H - reset, C
    this->z80->NF(false);
    this->z80->HF(false);
    this->z80->CF(reg);
    return (reg >> 1) | (this->z80->CF() << 7);
}

uint8_t Rotate::RR(uint8_t reg){
    //Flags: N & H - reset, C
    bool C;
    uint8_t nreg = reg >> 1;
    C = nreg;
    nreg = nreg | (this->z80->CF() << 7);
    this->z80->NF(false);
    this->z80->HF(false);
    this->z80->CF(C);
    return nreg;
}

uint8_t     Rotate::SRA     (uint8_t reg){
    return 0;
}
uint8_t     Rotate::SRL     (uint8_t reg){
    return 0;
}

uint8_t     Rotate::SLA     (uint8_t reg){
    return 0;
}
uint8_t     Rotate::SLL     (uint8_t reg){
    return 0;
}