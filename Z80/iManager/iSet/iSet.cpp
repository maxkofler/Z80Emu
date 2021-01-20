#include "iSet.h"

ISet::ISet(Z80* z80, Log* log){
    this->z80 = z80;
    this->log = log;
    this->mainIS = new MainIS(this->z80, this->log);


    this->opsImplemented = 64;
    this->opBytes = new uint8_t[this->opsImplemented] {
        0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
        1, 2, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0,
        1, 2, 2, 0, 0, 0, 1, 0, 1, 0, 2, 0, 0, 0, 1, 0,
        1, 2, 2, 0, 0, 0, 1, 0, 1, 0, 2, 0, 0, 0, 1, 0
    };
}

uint8_t ISet::getOPBytes(uint8_t opcode){
    if (opcode <= this->opsImplemented){
        log->log("ISet-getOPBytes", "operands to fetch: " + Log::toHexString(this->opBytes[opcode]), Log::D3);
        return this->opBytes[opcode];
    }else{
        log->log("ISet-getOPBytes", "Current opcode not implemented, returning 0 operands for safety!", Log::W);
        return 0;
    }
    
}

void ISet::execIS(uint8_t* is){
    mainIS->exec(is);
}

uint8_t ISet::getISCycles(uint8_t opcode){
    return mainIS->getCycles(opcode);
}