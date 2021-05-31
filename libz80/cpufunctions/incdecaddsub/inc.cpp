#include "cpufunctions/incdecaddsub.h"

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