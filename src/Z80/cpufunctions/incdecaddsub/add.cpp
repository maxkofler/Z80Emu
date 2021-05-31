#include "cpufunctions/incdecaddsub.h"

uint8_t IncDecAddSub::add(uint8_t reg1, uint8_t reg2){
    //Affected:     N, P/V(overflow), H, Z, S
    int nreg = reg1 + reg2;
    uint8_t nreg8 = nreg;
    
    z80->NF(false);                 //Not a substraction
    z80->PVF(nreg > 255);           //Set overflow flag if needed
    
    z80->ZF(nreg8 == 0);

    return nreg8;
}

uint8_t IncDecAddSub::adc(uint8_t reg1, uint8_t reg2){
    return reg1 + reg2 + z80->CF();
}

uint16_t IncDecAddSub::addX16(uint16_t reg1, uint16_t reg2){
    //Affected:     C, N, H
    z80->NF(false);
    return 0;
}

uint16_t IncDecAddSub::adcX16(uint16_t reg1, uint16_t reg2){
    //Affected: C, N, P/V(overflow), H, Z, S    
    int32_t nreg = reg1 + reg2 + z80->CF();
    uint16_t nreg16 = nreg;

    z80->CF(nreg < UINT16_MAX);     //Carry
    z80->NF(true);                  //Is a substraction
    z80->PVF(nreg < 0);             //Overflow
    z80->ZF(nreg16 == 0);           //Zero flag
    z80->SF(nreg16 >> 15);          //Sign (15th bit)

    return nreg16;
}