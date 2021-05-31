#include "z80emu.h"

Z80::Z80(){
    FUN();

    this->ioManager = new IOManager(this);
    this->mM = new MemoryManager();
    this->iManager = new IManager(this);

    this->cycles = 0;
}

Z80::~Z80(){
    FUN();

    delete this->ioManager;
    delete this->mM;
    delete this->iManager;
}
