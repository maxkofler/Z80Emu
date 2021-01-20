#include "incdecaddsub.h"

IncDecAddSub::IncDecAddSub(Z80* z80){
    this->z80 = z80;
}


//Increment

uint8_t IncDecAddSub::inc(uint8_t reg){
    //Affected:     N, P/V(overflow), H, Z, S
    int nreg = reg + 1;
    uint8_t nreg8 = nreg;
    
    z80->NF(false);                 //Not a substraction
    z80->PVF(nreg > 255);           //Set overflow flag if needed
    
    z80->ZF(nreg8 == 0);

    return nreg8;
}
uint16_t IncDecAddSub::incX16(uint16_t reg){
    //No registers affected
    return reg+1;
}


//Decrement

uint8_t IncDecAddSub::dec(uint8_t reg){
    //Affected:     N, P/V(overflow), H, Z, S
    int nreg = reg - 1;
    uint8_t nreg8 = nreg;
    
    z80->NF(true);                  //A substraction
    z80->PVF(nreg < 0);             //Set overflow flag if needed
    
    z80->ZF(nreg8 == 0);

    return nreg8;
}
uint16_t IncDecAddSub::decX16(uint16_t reg){
    //No registers affected
    return reg-1;
}


//Add

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
    return 0;
}
uint16_t IncDecAddSub::addX16(uint16_t reg1, uint16_t reg2){
    //Affected:     C, N, H
    z80->NF(false);
    return 0;
}


//Sub

uint8_t IncDecAddSub::sub(uint8_t reg1, uint8_t reg2){
    //Affected:     N, P/V(overflow), H, Z, S
    int nreg = reg1 - reg2;
    uint8_t nreg8 = nreg;
    
    z80->NF(true);                  //A substraction
    z80->PVF(nreg < 0);             //Set overflow flag if needed
    
    z80->ZF(nreg8 == 0);            //Set zero flag

    return nreg8;
}
uint8_t IncDecAddSub::sbc(uint8_t reg1, uint8_t reg2){
    return 0;
}
uint16_t IncDecAddSub::subX16(uint16_t reg1, uint16_t reg2){
    //Affected:     C, N, H
    z80->NF(true);
    return 0;
}


