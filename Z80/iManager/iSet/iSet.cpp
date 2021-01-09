#include "iSet.h"

ISet::ISet(Z80* z80, Log* log){
    this->z80 = z80;
    this->log = log;
    this->mainIS = new MainIS(this->z80, this->log);
}

uint8_t ISet::getOPBytes(uint8_t opcode){
    uint8_t opBytes[4] = {0, 2, 0, 0};
    return opBytes[opcode];
}

void ISet::execIS(uint8_t* is){
    mainIS->exec(is);
}

uint8_t ISet::getISCycles(uint8_t opcode){
    return mainIS->getCycles(opcode);
}