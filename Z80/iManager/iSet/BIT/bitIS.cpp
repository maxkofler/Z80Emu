#include "bitIS.h"

BitIS::BitIS(Z80* z80, Log* log){
    this->z = z80;
    this->log = log;
    rot = new Rotate(this->z);
}


void BitIS::exec(uint8_t op){
    switch(op){
        case 0x00:  z->B(rot->RLC(z->B()));                                                             break;  //RLC B
        case 0x01:  z->C(rot->RLC(z->C()));                                                             break;  //RLC C

        default:    log->logUnimplemented(op);                                                          break;  //Not implemented instructions
    }
}