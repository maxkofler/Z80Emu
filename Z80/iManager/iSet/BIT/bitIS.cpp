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
        case 0x02:  z->D(rot->RLC(z->D()));                                                             break;  //RLC D
        case 0x03:  z->E(rot->RLC(z->E()));                                                             break;  //RLC E
        case 0x04:  z->H(rot->RLC(z->H()));                                                             break;  //RLC H
        case 0x05:  z->L(rot->RLC(z->L()));                                                             break;  //RLC L
        case 0x06:  z->mM->set(z->HL(), rot->RLC(z->mM->get(z->HL())));                                 break;  //RLC (HL)
        case 0x07:  z->A(rot->RLC(z->A()));                                                             break;  //RLC A
        case 0x08:  z->B(rot->RRC(z->B()));                                                             break;  //RRC B
        case 0x09:  z->C(rot->RRC(z->B()));                                                             break;  //RRC C
        case 0x0A:  z->D(rot->RRC(z->B()));                                                             break;  //RRC D
        case 0x0B:  z->E(rot->RRC(z->B()));                                                             break;  //RRC E
        case 0x0C:  z->H(rot->RRC(z->B()));                                                             break;  //RRC H
        case 0x0D:  z->L(rot->RRC(z->B()));                                                             break;  //RRC L
        case 0x0E:  z->mM->set(z->HL(), rot->RRC(z->mM->get(z->HL())));                                 break;  //RRC (HL)
        case 0x0F:  z->A(rot->RRC(z->B()));                                                             break;  //RRC A

        case 0x10:  z->B(rot->RL(z->B()));                                                              break;  //RL B
        case 0x11:  z->C(rot->RL(z->C()));                                                              break;  //RL C
        case 0x12:  z->D(rot->RL(z->D()));                                                              break;  //RL D
        case 0x13:  z->E(rot->RL(z->E()));                                                              break;  //RL E
        case 0x14:  z->H(rot->RL(z->H()));                                                              break;  //RL H
        case 0x15:  z->L(rot->RL(z->L()));                                                              break;  //RL L 
        case 0x16:  z->mM->set(z->HL(), rot->RL(z->mM->get(z->HL())));                                  break;  //RL (HL)
        case 0x17:  z->A(rot->RL(z->A()));                                                              break;  //RL A
        case 0x18:  z->B(rot->RR(z->B()));                                                              break;  //RR B
        case 0x19:  z->C(rot->RR(z->C()));                                                              break;  //RR C
        case 0x1A:  z->D(rot->RR(z->D()));                                                              break;  //RR D
        case 0x1B:  z->E(rot->RR(z->E()));                                                              break;  //RR E
        case 0x1C:  z->H(rot->RR(z->H()));                                                              break;  //RR H
        case 0x1D:  z->L(rot->RR(z->L()));                                                              break;  //RR L
        case 0x1E:  z->mM->set(z->HL(), rot->RR(z->mM->get(z->HL())));                                  break;  //RR (HL)
        case 0x1F:  z->A(rot->RR(z->A()));                                                              break;  //RR A

        case 0x20:  z->B(rot->SLA(z->B()));                                                             break;  //SLA B
        case 0x21:  z->C(rot->SLA(z->C()));                                                             break;  //SLA C
        case 0x22:  z->D(rot->SLA(z->D()));                                                             break;  //SLA D
        case 0x23:  z->E(rot->SLA(z->E()));                                                             break;  //SLA E
        case 0x24:  z->H(rot->SLA(z->H()));                                                             break;  //SLA H
        case 0x25:  z->L(rot->SLA(z->L()));                                                             break;  //SLA L
        case 0x26:  z->mM->set(z->HL(), rot->SLA(z->mM->get(z->HL())));                                 break;  //SLA (HL)
        case 0x27:  z->A(rot->SLA(z->A()));                                                             break;  //SLA A
        case 0x28:  z->B(rot->SRA(z->B()));                                                             break;  //SRA B
        case 0x29:  z->C(rot->SRA(z->C()));                                                             break;  //SRA C
        case 0x2A:  z->D(rot->SRA(z->D()));                                                             break;  //SRA D
        case 0x2B:  z->E(rot->SRA(z->E()));                                                             break;  //SRA E
        case 0x2C:  z->H(rot->SRA(z->H()));                                                             break;  //SRA H
        case 0x2D:  z->L(rot->SRA(z->L()));                                                             break;  //SRA L
        case 0x2E:  z->mM->set(z->HL(), rot->SRA(z->mM->get(z->HL())));                                 break;  //SRA (HL)
        case 0x2F:  z->A(rot->SRA(z->A()));                                                             break;  //SRA A

        case 0x30:  z->B(rot->SLL(z->B()));                                                             break;  //SLL B
        case 0x31:  z->C(rot->SLL(z->C()));                                                             break;  //SLL C
        case 0x32:  z->D(rot->SLL(z->D()));                                                             break;  //SLL D
        case 0x33:  z->E(rot->SLL(z->E()));                                                             break;  //SLL E
        case 0x34:  z->H(rot->SLL(z->H()));                                                             break;  //SLL H
        case 0x35:  z->L(rot->SLL(z->L()));                                                             break;  //SLL L
        case 0x36:  z->mM->set(z->HL(), rot->SLL(z->mM->get(z->HL())));                                 break;  //SLL (HL)
        case 0x37:  z->A(rot->SLL(z->A()));                                                             break;  //SLL A
        case 0x38:  z->B(rot->SRL(z->B()));                                                             break;  //SRL B
        case 0x39:  z->C(rot->SRL(z->C()));                                                             break;  //SRL C
        case 0x3A:  z->D(rot->SRL(z->D()));                                                             break;  //SRL D
        case 0x3B:  z->E(rot->SRL(z->E()));                                                             break;  //SRL E
        case 0x3C:  z->H(rot->SRL(z->H()));                                                             break;  //SRL H
        case 0x3D:  z->L(rot->SRL(z->L()));                                                             break;  //SRL L
        case 0x3E:  z->mM->set(z->HL(), rot->SRL(z->mM->get(z->HL())));                                 break;  //SRL (HL)
        case 0x3F:  z->A(rot->SRL(z->A()));                                                             break;  //SRL A
        
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