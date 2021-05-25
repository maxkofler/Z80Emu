#include "bitIS.h"

BitIS::BitIS(Z80* z80){
    FUN();
    
    this->z = z80;
    this->rot = new Rotate(this->z);
    this->bit = new Bit(this->z);

    this->p_fillArrays();
}

BitIS::~BitIS(){
    FUN();

    delete[] this->_opCycles;
}