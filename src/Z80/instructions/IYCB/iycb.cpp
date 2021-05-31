#include "instructions/iycb.h"

IYCB::IYCB(Z80* z80){
    FUN();

    this->z = z80;

    this->p_fillArrays();
}

IYCB::~IYCB(){
    FUN();
    
    delete[] this->_opCycles;
}