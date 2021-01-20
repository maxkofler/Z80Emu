#include "mainIs.h"

MainIS::MainIS(Z80* z80, Log* log){
    this->z = z80;
    this->log = log;
    this->idas = new IncDecAddSub(this->z);
    this->rot = new Rotate(this->z);
    this->arit = new Arithmetic(this->z);
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
        case 0x07:  z->A(rot->RLC(z->A()));                                                             break;  //RLCA
        case 0x08:  log->logUnimplemented(op);                                                          break;  //EX AF, AF'        NOT IMPLEMENTED YET!
        case 0x09:  z->HL(idas->addX16(z->HL(), z->BC()));                                              break;  //ADD HL, BC
        case 0x0A:  z->A(z->mM->get(z->BC()));                                                          break;  //LD A, (BC)
        case 0x0B:  z->BC(idas->decX16(z->BC()));                                                       break;  //DEC BC
        case 0x0C:  z->C(idas->inc(z->C()));                                                            break;  //INC C
        case 0x0D:  z->C(idas->dec(z->C()));                                                            break;  //DEC C
        case 0x0E:  z->C(is[1]);                                                                        break;  //LD C, *
        case 0x0F:  z->A(rot->RRC(z->A()));                                                             break;  //RRCA

        case 0x10:  log->logUnimplemented(op);                                                          break;  //DJNZ *            NOT IMPLEMENTED YET!
        case 0x11:  z->DE(z->getX16(is[1], is[2]));                                                     break;  //LD DE, **
        case 0x12:  z->mM->set(z->DE(), z->A());                                                        break;  //LC (DE), A
        case 0x13:  z->DE(idas->incX16(z->DE()));                                                       break;  //INC DE
        case 0x14:  z->D(idas->inc(z->D()));                                                            break;  //INC D
        case 0x15:  z->D(idas->dec(z->D()));                                                            break;  //DEC D
        case 0x16:  z->D(is[1]);                                                                        break;  //LD D, *
        case 0x17:  z->A(rot->RL(z->A()));                                                              break;  //RLA
        case 0x18:  log->logUnimplemented(op);                                                          break;  //JR *              NOT IMPLEMENTED YET!
        case 0x19:  z->HL(idas->addX16(z->HL(), z->DE()));                                              break;  //ADD HL, DE
        case 0x1A:  z->A(z->mM->get(z->DE()));                                                          break;  //LD A, (DE)
        case 0x1B:  z->DE(idas->decX16(z->DE()));                                                       break;  //DEC DE
        case 0x1C:  z->E(idas->inc(z->E()));                                                            break;  //INC E
        case 0x1D:  z->E(idas->dec(z->E()));                                                            break;  //DEC E
        case 0x1E:  z->E(is[1]);                                                                        break;  //LD E, *
        case 0x1F:  z->A(rot->RR(z->A()));                                                              break;  //RRA
        
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
        case 0x2B:  z->HL(idas->decX16(z->HL()));                                                       break;  //DEC HL
        case 0x2C:  z->L(idas->inc(z->L()));                                                            break;  //INC L
        case 0x2D:  z->L(idas->dec(z->L()));                                                            break;  //DEC L
        case 0x2E:  z->L(is[1]);                                                                        break;  //LD L, *
        case 0x2F:  log->logUnimplemented(op);                                                          break;  //CPL              NOT IMPLEMENTED YET!

        case 0x30:  log->logUnimplemented(op);                                                          break;  //JR NC, *         NOT IMPLEMENTED YET!
        case 0x31:  z->SP(z->getX16(is[1], is[2]));                                                     break;  //LD SP, **
        case 0x32:  z->mM->set(z->getX16(is[1], is[2]), z->A());                                        break;  //LD (**), A
        case 0x33:  z->SP(idas->incX16(z->SP()));                                                       break;  //INC SP
        case 0x34:  log->logUnimplemented(op);                                                          break;  //INC (HL)         NIY!
        case 0x35:  log->logUnimplemented(op);                                                          break;  //DEC (HL)         NIY!
        case 0x36:  z->mM->set(z->HL(), is[1]);                                                         break;  //LD (HL), *
        case 0x37:  log->logUnimplemented(op);                                                          break;  //SCF              NIY!
        case 0x38:  log->logUnimplemented(op);                                                          break;  //JR C, *          NIY!
        case 0x39:  z->HL(idas->addX16(z->HL(), z->SP()));                                              break;  //ADD HL, SP
        case 0x3A:  z->A(z->mM->get(z->getX16(is[1], is[2])));                                          break;  //LD A, (**)
        case 0x3B:  z->SP(idas->decX16(z->SP()));                                                       break;  //DEC SP
        case 0x3C:  z->A(idas->inc(z->A()));                                                            break;  //INC A
        case 0x3D:  z->A(idas->dec(z->A()));                                                            break;  //DEC A
        case 0x3E:  z->A(is[1]);                                                                        break;  //LD A, *
        case 0x3F:  z->CF(!z->CF()); z->HF(!z->HF());                                                   break;  //CCF
        
        case 0x40:  z->B(z->B());                                                                       break;  //LD B, B
        case 0x41:  z->B(z->C());                                                                       break;  //LD B, C
        case 0x42:  z->B(z->D());                                                                       break;  //LD B, D
        case 0x43:  z->B(z->E());                                                                       break;  //LD B, E
        case 0x44:  z->B(z->H());                                                                       break;  //LD B, H
        case 0x45:  z->B(z->L());                                                                       break;  //LD B, L
        case 0x46:  z->B(z->mM->get(z->HL()));                                                          break;  //LD B, (HL)
        case 0x47:  z->B(z->A());                                                                       break;  //LD B, A
        case 0x48:  z->C(z->B());                                                                       break;  //LD C, B
        case 0x49:  z->C(z->C());                                                                       break;  //LD C, C
        case 0x4A:  z->C(z->D());                                                                       break;  //LD C, D
        case 0x4B:  z->C(z->E());                                                                       break;  //LD C, E
        case 0x4C:  z->C(z->H());                                                                       break;  //LD C, H
        case 0x4D:  z->C(z->L());                                                                       break;  //LD C, L
        case 0x4E:  z->C(z->mM->get(z->HL()));                                                          break;  //LD C, (HL)
        case 0x4F:  z->C(z->A());                                                                       break;  //LD C, A

        case 0x50:  z->D(z->B());                                                                       break;  //LD D, B
        case 0x51:  z->D(z->C());                                                                       break;  //LD D, C
        case 0x52:  z->D(z->D());                                                                       break;  //LD D, D
        case 0x53:  z->D(z->E());                                                                       break;  //LD D, E
        case 0x54:  z->D(z->H());                                                                       break;  //LD D, H
        case 0x55:  z->D(z->L());                                                                       break;  //LD D, L
        case 0x56:  z->D(z->mM->get(z->HL()));                                                          break;  //LD D, (HL)
        case 0x57:  z->D(z->A());                                                                       break;  //LD D, A
        case 0x58:  z->E(z->B());                                                                       break;  //LD E, B
        case 0x59:  z->E(z->C());                                                                       break;  //LD E, C
        case 0x5A:  z->E(z->D());                                                                       break;  //LD E, D
        case 0x5B:  z->E(z->E());                                                                       break;  //LD E, E
        case 0x5C:  z->E(z->H());                                                                       break;  //LD E, H
        case 0x5D:  z->E(z->L());                                                                       break;  //LD E, L
        case 0x5E:  z->E(z->mM->get(z->HL()));                                                          break;  //LD E, (HL)
        case 0x5F:  z->E(z->A());                                                                       break;  //LD E, A

        case 0x60:  z->H(z->B());                                                                       break;  //LD H, B
        case 0x61:  z->H(z->C());                                                                       break;  //LD H, C
        case 0x62:  z->H(z->D());                                                                       break;  //LD H, D
        case 0x63:  z->H(z->E());                                                                       break;  //LD H, E
        case 0x64:  z->H(z->H());                                                                       break;  //LD H, H
        case 0x65:  z->H(z->L());                                                                       break;  //LD H, L
        case 0x66:  z->H(z->mM->get(z->HL()));                                                          break;  //LD H, (HL)
        case 0x67:  z->H(z->A());                                                                       break;  //LD H, A
        case 0x68:  z->L(z->B());                                                                       break;  //LD L, B
        case 0x69:  z->L(z->C());                                                                       break;  //LD L, C
        case 0x6A:  z->L(z->D());                                                                       break;  //LD L, D
        case 0x6B:  z->L(z->E());                                                                       break;  //LD L, E
        case 0x6C:  z->L(z->H());                                                                       break;  //LD L, H
        case 0x6D:  z->L(z->L());                                                                       break;  //LD L, L
        case 0x6E:  z->L(z->mM->get(z->HL()));                                                          break;  //LD L, (HL)
        case 0x6F:  z->L(z->A());                                                                       break;  //LD L, A
        
        case 0x70:  z->mM->set(z->HL(), z->B());                                                        break;  //LD (HL), B
        case 0x71:  z->mM->set(z->HL(), z->C());                                                        break;  //LD (HL), C
        case 0x72:  z->mM->set(z->HL(), z->D());                                                        break;  //LD (HL), D
        case 0x73:  z->mM->set(z->HL(), z->E());                                                        break;  //LD (HL), E
        case 0x74:  z->mM->set(z->HL(), z->H());                                                        break;  //LD (HL), H
        case 0x75:  z->mM->set(z->HL(), z->L());                                                        break;  //LD (HL), L
        case 0x76:  z->HALT(true);                                                                      break;  //HALT
        case 0x77:  z->mM->set(z->HL(), z->A());                                                        break;  //LD (HL), A
        case 0x78:  z->A(z->B());                                                                       break;  //LD A, B
        case 0x79:  z->A(z->C());                                                                       break;  //LD A, C
        case 0x7A:  z->A(z->D());                                                                       break;  //LD A, D
        case 0x7B:  z->A(z->E());                                                                       break;  //LD A, E
        case 0x7C:  z->A(z->H());                                                                       break;  //LD A, H
        case 0x7D:  z->A(z->L());                                                                       break;  //LD A, L
        case 0x7E:  z->A(z->mM->get(z->HL()));                                                          break;  //LD A, (HL)
        case 0x7F:  z->A(z->B());                                                                       break;  //LD A, A

        

        default:    log->logUnimplemented(op);                                                          break;  //Everything unimplemented
    };
}