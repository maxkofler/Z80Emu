#include "mainIs.h"

MainIS::MainIS(Z80* z80){
    FUN();

    this->z = z80;

    this->idas = new IncDecAddSub(this->z);
    this->rot = new Rotate(this->z);
    this->arit = new Arithmetic(this->z);
    this->cpctl = new CPUctl(this->z);

    this->p_fillArrays();
}

MainIS::~MainIS(){
    FUN();

    delete this->idas;
    delete this->rot;
    delete this->arit;
    delete this->cpctl;

    delete[] this->_opBytes;
    delete[] this->_opCycles;
}