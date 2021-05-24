#include "../z80.h"

Z80::Z80(){
    FUN();

    this->mM = new MemoryManager();
    this->iManager = new IManager(this);

    this->cycles = 0;
}

Z80::~Z80(){
    FUN();

    delete this->mM;
    delete this->iManager;
}