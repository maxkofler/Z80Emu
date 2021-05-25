#include "extIS.h"

ExtIS::ExtIS(Z80* z80){
    FUN();

    this->z = z80;

    this->p_fillArrays();
}

ExtIS::~ExtIS(){
    FUN();
    
    delete[] this->_opBytes;
    delete[] this->_opCycles;
}