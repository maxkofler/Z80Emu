#include "iycb.h"

IYCB::IYCB(Z80* z80){
    this->z = z80;
}

void IYCB::exec(uint8_t* is){
    uint8_t op = is[0];
    uint8_t o = is[1];
    uint16_t x = z->IX() + o;
    uint8_t v = z->mM->get(x);
    switch(op){


        default:    log->logUnimplemented(op);                                                          break;  //Not implemented instructions
    }
}