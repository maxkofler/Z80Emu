#include "bitIS.h"

BitIS::BitIS(Z80* z80, Log* log){
    this->z = z80;
    this->log = log;
    this->rot = new Rotate(this->z);
    this->bit = new Bit(this->z);
}


void BitIS::exec(uint8_t op){
    switch(op){
        case 0x00:  z->B(rot->RLC(z->B()));                                                             break;  //RLC B
        case 0x01:  z->C(rot->RLC(z->C()));                                                             break;  //RLC C
        //
        case 0x08:  z->B(rot->RRC(z->B()));                                                             break;  //RRC B

        case 0x10:  z->B(rot->RL(z->B()));                                                              break;  //RL B
        //
        case 0x18:  z->B(rot->RR(z->B()));                                                              break;  //RR B

        case 0x20:  z->B(rot->SLA(z->B()));                                                             break;  //SLA B
        //
        case 0x28:  z->B(rot->SRA(z->B()));                                                             break;  //SRA B

        case 0x30:  z->B(rot->SLL(z->B()));                                                             break;  //SLL B
        //
        case 0x38:  z->B(rot->SRL(z->B()));                                                             break;  //SRL B

        case 0x40:  bit->bit(0, z->B());                                                                break;  //BIT 0, B
        case 0x41:  bit->bit(0, z->C());                                                                break;  //BIT 0, C
        //...

        case 0x80:  z->B(bit->res(0, z->B()));                                                          break;  //RES 0, B
        case 0x81:  z->C(bit->res(0, z->C()));                                                          break;  //RES 0, B
        //...

        case 0xC0:  z->B(bit->set(0, z->B()));                                                          break;  //RES 0, B
        case 0xC1:  z->C(bit->set(0, z->C()));                                                          break;  //RES 0, B
        //...


        default:    log->logUnimplemented(op);                                                          break;  //Not implemented instructions
    }
}