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
        case 0x0F:  log->logUnimplemented(op);                                                          break;  //RRCA              NOT IMPLEMENTED YET!

        case 0x10:  log->logUnimplemented(op);                                                          break;  //DJNZ *            NOT IMPLEMENTED YET!
        case 0x11:  z->DE(z->getX16(is[1], is[2]));                                                     break;  //LD DE, **
        case 0x12:  z->mM->set(z->DE(), z->A());                                                        break;  //LC (DE), A
        case 0x13:  z->DE(idas->incX16(z->DE()));                                                       break;  //INC DE
        case 0x14:  z->D(idas->inc(z->D()));                                                            break;  //INC D
        case 0x15:  z->D(idas->dec(z->D()));                                                            break;  //DEC D
        case 0x16:  z->D(is[1]);                                                                        break;  //LD D, *
        case 0x17:  log->logUnimplemented(op);                                                          break;  //RLA               NOT IMPLEMENTED YET!
        case 0x18:  log->logUnimplemented(op);                                                          break;  //JR *              NOT IMPLEMENTED YET!
        case 0x19:  z->HL(idas->addX16(z->HL(), z->DE()));                                              break;  //ADD HL, DE
        case 0x1A:  z->A(z->mM->get(z->DE()));                                                          break;  //LD A, (DE)
        case 0x1B:  z->DE(idas->decX16(z->DE()));                                                       break;  //DEC DE
        case 0x1C:  z->E(idas->inc(z->E()));                                                            break;  //INC E
        case 0x1D:  z->E(idas->dec(z->E()));                                                            break;  //DEC E
        case 0x1E:  z->E(is[1]);                                                                        break;  //LD E, *
        case 0x1F:  log->logUnimplemented(op);                                                          break;  //RRA              NOT IMPLEMENTED YET!
        
        case 0x20:  log->logUnimplemented(op);                                                          break;  //JR NZ; *         NOT IMPLEMENTED YET!
        case 0x21:  z->HL(z->getX16(is[1], is[2]));                                                     break;  //LD HL, **
        case 0x22:  z->mM->setX16(z->getX16(is[1], is[2]), z->HL());                                    break;  //LD (**), HL
        case 0x23:  z->HL(idas->incX16(z->HL()));                                                       break;  //INC HL
        case 0x24:  z->H(idas->inc(z->H()));                                                            break;  //INC H
        case 0x25:  z->H(idas->dec(z->H()));                                                            break;  //DEC H
        case 0x26:  z->H(is[1]);                                                                        break;  //LD H, *
        case 0x27:  log->logUnimplemented(op);                                                          break;  //DAA              NOT IMPLEMENTED YET!
        case 0x28:  log->logUnimplemented(op);                                                          break;  //JR Z, *          NOT IMPLEMENTED YET!
        case 0x29:  z->HL(idas->addX16(z->HL(), z->HL()));                                              break;  //ADD HL, HL
        case 0x2A:  z->HL(z->mM->getX16(z->getX16(is[1], is[2])));                                      break;  //LD HL, (**)
        case 0x2B:  z->DE(idas->decX16(z->DE()));                                                       break;  //DEC DE
        case 0x2C:  z->E(idas->inc(z->E()));                                                            break;  //INC E
        case 0x2D:  z->E(idas->dec(z->E()));                                                            break;  //DEC E
        case 0x2E:  z->E(is[1]);                                                                        break;  //LD E, *
        case 0x2F:  log->logUnimplemented(op);                                                          break;  //RRA              NOT IMPLEMENTED YET!
        
        
        
        
        
        
        
        
        case 0x67:  z->HALT(true);                                                                      break;  //HALT

        default:    log->logUnimplemented(op);                                                          break;  //Everything unimplemented
    };
}