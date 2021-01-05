#include "incdecaddsub.h"

IncDecAddSub::IncDecAddSub(Z80* z80){
    this->z80 = z80;
}

uint8_t IncDecAddSub::inc(uint8_t reg){

}
uint16_t IncDecAddSub::incX16(uint16_t reg){
    //No registers affected
    return reg+1;
}

uint8_t IncDecAddSub::dec(uint8_t reg){
    
}
uint16_t IncDecAddSub::decX16(uint16_t reg){
    //No registers affected
    return reg-1;
}

uint8_t IncDecAddSub::add(uint8_t reg1, uint8_t reg2){

}

uint8_t IncDecAddSub::sub(uint8_t reg1, uint8_t reg2){
    
}


