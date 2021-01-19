#include "mainIs.h"

MainIS::MainIS(Z80* z80, Log* log){
    this->z = z80;
    this->log = log;
    this->idas = new IncDecAddSub(this->z);
}

uint8_t MainIS::getCycles(uint8_t op){
    if (op <= 16){
        return cycles[op];
    }else{
        return 0;
    }
}

void MainIS::exec(uint8_t* is){
    uint8_t op = is[0];
    switch(op){
        case 0x00:                                                                                      break;  //NOP
        case 0x01:  z->BC(z->getX16(is[1], is[2]));                                                     break;  //LD BC, **
        case 0x02:  z->mM->set(z->BC(), z->A());                                                        break;  //LC (BC), A
        case 0x03:  z->BC(idas->incX16(z->BC()));                                                       break;  //INC BC
        case 0x04:  z->B(idas->inc(z->B()));                                                            break;  //INC B
        case 0x05:  z->B(idas->dec(z->B()));                                                            break;  //DEC B
        case 0x06:  z->B(is[1]);                                                                        break;  //LD B, *
        case 0x07:  log->logUnimplemented(op);                                                          break;  //RLCA              NOT IMPLEMENTED YET!
        case 0x08:  log->logUnimplemented(op);                                                          break;  //EX AF, AF'        NOT IMPLEMENTED YET!
        case 0x09:  z->HL(idas->addX16(z->HL(), z->BC()));                                              break;  //ADD HL, BC
        case 0x0A:  z->A(z->mM->get(z->BC()));                                                          break;  //LD A, (BC)
        case 0x0B:  z->BC(idas->decX16(z->BC()));                                                       break;  //DEC BC
        case 0x0C:  z->C(idas->inc(z->C()));                                                            break;  //INC C
        case 0x0D:  z->C(idas->dec(z->C()));                                                            break;  //DEC C
        case 0x0E:  z->C(is[1]);                                                                        break;  //LD C, *
        case 0x0F:  log->logUnimplemented(op);                                                          break;  //RRCA

        case 0x67:  z->HALT(true);                                                                      break;  //HALT

        default:    log->logUnimplemented(op);                                                          break;  //Everything unimplemented
    };
}