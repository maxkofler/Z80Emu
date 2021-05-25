#include "iomanager.h"


//Flags affected:     N(r)    PV(p)   H(r)    Z(d)    S(d)
uint8_t IOManager::in(uint8_t addr){
    FUN();

    this->z80->NF(false);
    this->z80->HF(false);

    uint8_t buf = this->read(addr);

    this->z80->ZF(buf == 0);
    this->z80->SF(buf >> 7);

    return buf;
}

bool IOManager::out(uint8_t addr, uint8_t data){
    FUN();

    return this->write(addr, data);
}