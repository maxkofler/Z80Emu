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
        case 0x42:  bit->bit(0, z->D());                                                                break;  //BIT 0, D
        case 0x43:  bit->bit(0, z->E());                                                                break;  //BIT 0, E
        case 0x44:  bit->bit(0, z->H());                                                                break;  //BIT 0, H
        case 0x45:  bit->bit(0, z->L());                                                                break;  //BIT 0, L
        case 0x46:  bit->bit(0, z->mM->get(z->HL()));                                                   break;  //BIT 0, (HL)
        case 0x47:  bit->bit(0, z->A());                                                                break;  //BIT 0, A
        case 0x48:  bit->bit(1, z->B());                                                                break;  //BIT 1, B
        case 0x49:  bit->bit(1, z->C());                                                                break;  //BIT 1, C
        case 0x4A:  bit->bit(1, z->D());                                                                break;  //BIT 1, D
        case 0x4B:  bit->bit(1, z->E());                                                                break;  //BIT 1, E
        case 0x4C:  bit->bit(1, z->H());                                                                break;  //BIT 1, H
        case 0x4D:  bit->bit(1, z->L());                                                                break;  //BIT 1, L
        case 0x4E:  bit->bit(1, z->mM->get(z->HL()));                                                   break;  //BIT 1, (HL)
        case 0x4F:  bit->bit(1, z->A());                                                                break;  //BIT 1, A

        case 0x50:  bit->bit(2, z->B());                                                                break;  //BIT 2, B
        case 0x51:  bit->bit(2, z->C());                                                                break;  //BIT 2, C
        case 0x52:  bit->bit(2, z->D());                                                                break;  //BIT 2, D
        case 0x53:  bit->bit(2, z->E());                                                                break;  //BIT 2, E
        case 0x54:  bit->bit(2, z->H());                                                                break;  //BIT 2, H
        case 0x55:  bit->bit(2, z->L());                                                                break;  //BIT 2, L
        case 0x56:  bit->bit(2, z->mM->get(z->HL()));                                                   break;  //BIT 2, (HL)
        case 0x57:  bit->bit(2, z->A());                                                                break;  //BIT 2, A
        case 0x58:  bit->bit(3, z->B());                                                                break;  //BIT 3, B
        case 0x59:  bit->bit(3, z->C());                                                                break;  //BIT 3, C
        case 0x5A:  bit->bit(3, z->D());                                                                break;  //BIT 3, D
        case 0x5B:  bit->bit(3, z->E());                                                                break;  //BIT 3, E
        case 0x5C:  bit->bit(3, z->H());                                                                break;  //BIT 3, H
        case 0x5D:  bit->bit(3, z->L());                                                                break;  //BIT 3, L
        case 0x5E:  bit->bit(3, z->mM->get(z->HL()));                                                   break;  //BIT 3, (HL)
        case 0x5F:  bit->bit(3, z->A());                                                                break;  //BIT 3, A

        case 0x60:  bit->bit(4, z->B());                                                                break;  //BIT 4, B
        case 0x61:  bit->bit(4, z->C());                                                                break;  //BIT 4, C
        case 0x62:  bit->bit(4, z->D());                                                                break;  //BIT 4, D
        case 0x63:  bit->bit(4, z->E());                                                                break;  //BIT 4, E
        case 0x64:  bit->bit(4, z->H());                                                                break;  //BIT 4, H
        case 0x65:  bit->bit(4, z->L());                                                                break;  //BIT 4, L
        case 0x66:  bit->bit(4, z->mM->get(z->HL()));                                                   break;  //BIT 4, (HL)
        case 0x67:  bit->bit(4, z->A());                                                                break;  //BIT 4, A
        case 0x68:  bit->bit(4, z->B());                                                                break;  //BIT 5, B
        case 0x69:  bit->bit(5, z->C());                                                                break;  //BIT 5, C
        case 0x6A:  bit->bit(5, z->D());                                                                break;  //BIT 5, D
        case 0x6B:  bit->bit(5, z->E());                                                                break;  //BIT 5, E
        case 0x6C:  bit->bit(5, z->H());                                                                break;  //BIT 5, H
        case 0x6D:  bit->bit(5, z->L());                                                                break;  //BIT 5, L
        case 0x6E:  bit->bit(5, z->mM->get(z->HL()));                                                   break;  //BIT 5, (HL)
        case 0x6F:  bit->bit(5, z->A());                                                                break;  //BIT 5, A

        case 0x70:  bit->bit(6, z->B());                                                                break;  //BIT 6, B
        case 0x71:  bit->bit(6, z->C());                                                                break;  //BIT 6, C
        case 0x72:  bit->bit(6, z->D());                                                                break;  //BIT 6, D
        case 0x73:  bit->bit(6, z->E());                                                                break;  //BIT 6, E
        case 0x74:  bit->bit(6, z->H());                                                                break;  //BIT 6, H
        case 0x75:  bit->bit(6, z->L());                                                                break;  //BIT 6, L
        case 0x76:  bit->bit(6, z->mM->get(z->HL()));                                                   break;  //BIT 6, (HL)
        case 0x77:  bit->bit(6, z->A());                                                                break;  //BIT 6, A
        case 0x78:  bit->bit(7, z->B());                                                                break;  //BIT 7, B
        case 0x79:  bit->bit(7, z->C());                                                                break;  //BIT 7, C
        case 0x7A:  bit->bit(7, z->D());                                                                break;  //BIT 7, D
        case 0x7B:  bit->bit(7, z->E());                                                                break;  //BIT 7, E
        case 0x7C:  bit->bit(7, z->H());                                                                break;  //BIT 7, H
        case 0x7D:  bit->bit(7, z->L());                                                                break;  //BIT 7, L
        case 0x7E:  bit->bit(7, z->mM->get(z->HL()));                                                   break;  //BIT 7, (HL)
        case 0x7F:  bit->bit(7, z->A());                                                                break;  //BIT 7, A

        case 0x80:  z->B(bit->res(0, z->B()));                                                          break;  //RES 0, B
        case 0x81:  z->C(bit->res(0, z->C()));                                                          break;  //RES 0, C
        case 0x82:  z->D(bit->res(0, z->D()));                                                          break;  //RES 0, D
        case 0x83:  z->E(bit->res(0, z->E()));                                                          break;  //RES 0, E
        case 0x84:  z->H(bit->res(0, z->H()));                                                          break;  //RES 0, H
        case 0x85:  z->L(bit->res(0, z->L()));                                                          break;  //RES 0, L
        case 0x86:  z->mM->set(z->HL(), bit->res(0, z->mM->get(z->HL())));                              break;  //RES 0, (HL)
        case 0x87:  z->A(bit->res(0, z->A()));                                                          break;  //RES 0, A
        case 0x88:  z->B(bit->res(1, z->B()));                                                          break;  //RES 1, B
        case 0x89:  z->C(bit->res(1, z->C()));                                                          break;  //RES 1, C
        case 0x8A:  z->D(bit->res(1, z->D()));                                                          break;  //RES 1, D
        case 0x8B:  z->E(bit->res(1, z->E()));                                                          break;  //RES 1, E
        case 0x8C:  z->H(bit->res(1, z->H()));                                                          break;  //RES 1, H
        case 0x8D:  z->L(bit->res(1, z->L()));                                                          break;  //RES 1, L
        case 0x8E:  z->mM->set(z->HL(), bit->res(1, z->mM->get(z->HL())));                              break;  //RES 1, (HL)
        case 0x8F:  z->A(bit->res(1, z->A()));                                                          break;  //RES 1, A
        
        case 0x90:  z->B(bit->res(2, z->B()));                                                          break;  //RES 2, B
        case 0x91:  z->C(bit->res(2, z->C()));                                                          break;  //RES 2, C
        case 0x92:  z->D(bit->res(2, z->D()));                                                          break;  //RES 2, D
        case 0x93:  z->E(bit->res(2, z->E()));                                                          break;  //RES 2, E
        case 0x94:  z->H(bit->res(2, z->H()));                                                          break;  //RES 2, H
        case 0x95:  z->L(bit->res(2, z->L()));                                                          break;  //RES 2, L
        case 0x96:  z->mM->set(z->HL(), bit->res(2, z->mM->get(z->HL())));                              break;  //RES 2, (HL)
        case 0x97:  z->A(bit->res(2, z->A()));                                                          break;  //RES 2, A
        case 0x98:  z->B(bit->res(3, z->B()));                                                          break;  //RES 3, B
        case 0x99:  z->C(bit->res(3, z->C()));                                                          break;  //RES 3, C
        case 0x9A:  z->D(bit->res(3, z->D()));                                                          break;  //RES 3, D
        case 0x9B:  z->E(bit->res(3, z->E()));                                                          break;  //RES 3, E
        case 0x9C:  z->H(bit->res(3, z->H()));                                                          break;  //RES 3, H
        case 0x9D:  z->L(bit->res(3, z->L()));                                                          break;  //RES 3, L
        case 0x9E:  z->mM->set(z->HL(), bit->res(3, z->mM->get(z->HL())));                              break;  //RES 3, (HL)
        case 0x9F:  z->A(bit->res(3, z->A()));                                                          break;  //RES 3, A

        case 0xA0:  z->B(bit->res(4, z->B()));                                                          break;  //RES 4, B
        case 0xA1:  z->C(bit->res(4, z->C()));                                                          break;  //RES 4, C
        case 0xA2:  z->D(bit->res(4, z->D()));                                                          break;  //RES 4, D
        case 0xA3:  z->E(bit->res(4, z->E()));                                                          break;  //RES 4, E
        case 0xA4:  z->H(bit->res(4, z->H()));                                                          break;  //RES 4, H
        case 0xA5:  z->L(bit->res(4, z->L()));                                                          break;  //RES 4, L
        case 0xA6:  z->mM->set(z->HL(), bit->res(4, z->mM->get(z->HL())));                              break;  //RES 4, (HL)
        case 0xA7:  z->A(bit->res(4, z->A()));                                                          break;  //RES 4, A
        case 0xA8:  z->B(bit->res(5, z->B()));                                                          break;  //RES 5, B
        case 0xA9:  z->C(bit->res(5, z->C()));                                                          break;  //RES 5, C
        case 0xAA:  z->D(bit->res(5, z->D()));                                                          break;  //RES 5, D
        case 0xAB:  z->E(bit->res(5, z->E()));                                                          break;  //RES 5, E
        case 0xAC:  z->H(bit->res(5, z->H()));                                                          break;  //RES 5, H
        case 0xAD:  z->L(bit->res(5, z->L()));                                                          break;  //RES 5, L
        case 0xAE:  z->mM->set(z->HL(), bit->res(5, z->mM->get(z->HL())));                              break;  //RES 5, (HL)
        case 0xAF:  z->A(bit->res(5, z->A()));                                                          break;  //RES 5, A

        case 0xB0:  z->B(bit->res(6, z->B()));                                                          break;  //RES 6, B
        case 0xB1:  z->C(bit->res(6, z->C()));                                                          break;  //RES 6, C
        case 0xB2:  z->D(bit->res(6, z->D()));                                                          break;  //RES 6, D
        case 0xB3:  z->E(bit->res(6, z->E()));                                                          break;  //RES 6, E
        case 0xB4:  z->H(bit->res(6, z->H()));                                                          break;  //RES 6, H
        case 0xB5:  z->L(bit->res(6, z->L()));                                                          break;  //RES 6, L
        case 0xB6:  z->mM->set(z->HL(), bit->res(6, z->mM->get(z->HL())));                              break;  //RES 6, (HL)
        case 0xB7:  z->A(bit->res(6, z->A()));                                                          break;  //RES 6, A
        case 0xB8:  z->B(bit->res(7, z->B()));                                                          break;  //RES 7, B
        case 0xB9:  z->C(bit->res(7, z->C()));                                                          break;  //RES 7, C
        case 0xBA:  z->D(bit->res(7, z->D()));                                                          break;  //RES 7, D
        case 0xBB:  z->E(bit->res(7, z->E()));                                                          break;  //RES 7, E
        case 0xBC:  z->H(bit->res(7, z->H()));                                                          break;  //RES 7, H
        case 0xBD:  z->L(bit->res(7, z->L()));                                                          break;  //RES 7, L
        case 0xBE:  z->mM->set(z->HL(), bit->res(7, z->mM->get(z->HL())));                              break;  //RES 7, (HL)
        case 0xBF:  z->A(bit->res(7, z->A()));                                                          break;  //RES 7, A

        case 0xC0:  z->B(bit->set(0, z->B()));                                                          break;  //RES 0, B
        case 0xC1:  z->C(bit->set(0, z->C()));                                                          break;  //RES 0, B
        //...


        default:    log->logUnimplemented(op);                                                          break;  //Not implemented instructions
    }
}