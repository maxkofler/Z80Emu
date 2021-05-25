#include "ixcb.h"

IXCB::IXCB(Z80* z80){
    FUN();

    this->z = z80;

    this->p_fillArrays();
}

IXCB::~IXCB(){
    delete[] this->_opCycles;
}