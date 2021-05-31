#include "cpufunctions/arithmetic.h"

Arithmetic::Arithmetic(Z80* z80){
    this->z80 = z80;
    this->idas = new IncDecAddSub(this->z80);
}

//Bitwise AND with 2 registers
uint8_t Arithmetic::AND(uint8_t reg1, uint8_t reg2){
    //Flags:    C(r), N(r), P(parity), H(s), Z, S
    uint8_t nreg = reg1 & reg2;

    z80->CF(false);     z80->NF(false);     z80->HF(true);
    z80->ZF(nreg == 0);

    z80->PVF(z80->getEvenParity(nreg));
    z80->SF(nreg>>7);

    return nreg;
}

//Bitwise OR with 2 registers
uint8_t Arithmetic::OR(uint8_t reg1, uint8_t reg2){
    //Flags:    C(r), N(r), P(parity), H(r), Z, S
    uint8_t nreg = reg1 | reg2;
    
    z80->CF(false);     z80->NF(false);     z80->HF(false);
    z80->ZF(nreg == 0);

    z80->PVF(z80->getEvenParity(nreg));
    z80->SF(nreg>>7);

    return nreg;
}

//Bitwise XOR with 2 registers
uint8_t Arithmetic::XOR(uint8_t reg1, uint8_t reg2){
    //Flags:    C(r), N(r), P(parity), H(r), Z, S
    uint8_t nreg = reg1 ^ reg2;
    
    z80->CF(false);     z80->NF(false);     z80->HF(false);
    z80->ZF(nreg == 0);

    z80->PVF(z80->getEvenParity(nreg));
    z80->SF(nreg>>7);
    return 0;
}

void Arithmetic::CP(uint8_t reg1, uint8_t reg2){
    idas->sub(reg1, reg2);
}
