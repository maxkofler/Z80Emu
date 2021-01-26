#include "ixcb.h"

IXCB::IXCB(Z80* z80){
    this->z = z80;

    //  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  A,  B,  C,  D,  E,  F

    this->cycles = new uint8_t[256]{
        23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,     //0x00
        23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,     //0x10
        23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,     //0x20
        23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,     //0x30

        20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,     //0x40
        20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,     //0x50
        20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,     //0x60
        20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,     //0x70

        23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,     //0x80
        23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,     //0x90
        23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,     //0xA0
        23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,     //0xB0
        23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,     //0xC0
        23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,     //0xD0
        23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,     //0xE0
        23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23      //0xF0
    };
}

uint8_t IXCB::getCycles(uint8_t op){
    log->log("IXCB::getCycles()", "IS " + Log::toHexString(op) + " takes " + std::to_string(this->cycles[op]) + " cycles!", Log::D3);
    return this->cycles[op];
}

void IXCB::exec(uint8_t* is){
    uint8_t op = is[0];
    uint8_t o = is[1];
    uint16_t x = z->IX() + o;
    uint8_t v = z->mM->get(x);
    switch(op){
        case 0x00:  z->B(rot->RLC(v));                                                                  break;  //RLC (IX+*), B
        case 0x01:  z->C(rot->RLC(v));                                                                  break;  //RLC (IX+*), C
        case 0x02:  z->D(rot->RLC(v));                                                                  break;  //RLC (IX+*), D
        case 0x03:  z->E(rot->RLC(v));                                                                  break;  //RLC (IX+*), E
        case 0x04:  z->H(rot->RLC(v));                                                                  break;  //RLC (IX+*), H
        case 0x05:  z->L(rot->RLC(v));                                                                  break;  //RLC (IX+*), L
        case 0x06:  z->mM->set(x, rot->RLC(v));                                                         break;  //RLC (IX+*)
        case 0x07:  z->A(rot->RLC(v));                                                                  break;  //RLC (IX+*), A
        case 0x08:  z->B(rot->RRC(v));                                                                  break;  //RRC (IX+*), B
        case 0x09:  z->C(rot->RRC(v));                                                                  break;  //RRC (IX+*), C
        case 0x0A:  z->D(rot->RRC(v));                                                                  break;  //RRC (IX+*), D
        case 0x0B:  z->E(rot->RRC(v));                                                                  break;  //RRC (IX+*), E
        case 0x0C:  z->H(rot->RRC(v));                                                                  break;  //RRC (IX+*), H
        case 0x0D:  z->L(rot->RRC(v));                                                                  break;  //RRC (IX+*), L
        case 0x0E:  z->mM->set(x, rot->RRC(v));                                                         break;  //RRC (IX+*)
        case 0x0F:  z->A(rot->RRC(v));                                                                  break;  //RRC (IX+*), A

        case 0x10:  z->B(rot->RL(v));                                                                   break;  //RL (IX+*), B
        case 0x11:  z->C(rot->RL(v));                                                                   break;  //RL (IX+*), C
        case 0x12:  z->D(rot->RL(v));                                                                   break;  //RL (IX+*), D
        case 0x13:  z->E(rot->RL(v));                                                                   break;  //RL (IX+*), E
        case 0x14:  z->H(rot->RL(v));                                                                   break;  //RL (IX+*), H
        case 0x15:  z->L(rot->RL(v));                                                                   break;  //RL (IX+*), L
        case 0x16:  z->mM->set(x, rot->RL(v));                                                          break;  //RL (IX+*), 
        case 0x17:  z->A(rot->RL(v));                                                                   break;  //RL (IX+*), A
        case 0x18:  z->B(rot->RR(v));                                                                   break;  //RR (IX+*), B
        case 0x19:  z->C(rot->RR(v));                                                                   break;  //RR (IX+*), C
        case 0x1A:  z->D(rot->RR(v));                                                                   break;  //RR (IX+*), D
        case 0x1B:  z->E(rot->RR(v));                                                                   break;  //RR (IX+*), E
        case 0x1C:  z->H(rot->RR(v));                                                                   break;  //RR (IX+*), H
        case 0x1D:  z->L(rot->RR(v));                                                                   break;  //RR (IX+*), L
        case 0x1E:  z->mM->set(x, rot->RR(v));                                                          break;  //RR (IX+*), 
        case 0x1F:  z->A(rot->RR(v));                                                                   break;  //RR (IX+*), A

        case 0x20:  z->B(rot->SLA(v));                                                                  break;  //SLA (IX+*), B
        case 0x21:  z->C(rot->SLA(v));                                                                  break;  //SLA (IX+*), C
        case 0x22:  z->D(rot->SLA(v));                                                                  break;  //SLA (IX+*), D
        case 0x23:  z->E(rot->SLA(v));                                                                  break;  //SLA (IX+*), E
        case 0x24:  z->H(rot->SLA(v));                                                                  break;  //SLA (IX+*), H
        case 0x25:  z->L(rot->SLA(v));                                                                  break;  //SLA (IX+*), L
        case 0x26:  z->mM->set(x, rot->SLA(v));                                                         break;  //SLA (IX+*), 
        case 0x27:  z->A(rot->SLA(v));                                                                  break;  //SLA (IX+*), A
        case 0x28:  z->B(rot->SRA(v));                                                                  break;  //SRA (IX+*), B
        case 0x29:  z->C(rot->SRA(v));                                                                  break;  //SRA (IX+*), C
        case 0x2A:  z->D(rot->SRA(v));                                                                  break;  //SRA (IX+*), D
        case 0x2B:  z->E(rot->SRA(v));                                                                  break;  //SRA (IX+*), E
        case 0x2C:  z->H(rot->SRA(v));                                                                  break;  //SRA (IX+*), H
        case 0x2D:  z->L(rot->SRA(v));                                                                  break;  //SRA (IX+*), L
        case 0x2E:  z->mM->set(x, rot->SRA(v));                                                         break;  //SRA (IX+*), 
        case 0x2F:  z->A(rot->SRA(v));                                                                  break;  //SRA (IX+*), A

        case 0x30:  z->B(rot->SLL(v));                                                                  break;  //SLL (IX+*), B
        case 0x31:  z->C(rot->SLL(v));                                                                  break;  //SLL (IX+*), C
        case 0x32:  z->D(rot->SLL(v));                                                                  break;  //SLL (IX+*), D
        case 0x33:  z->E(rot->SLL(v));                                                                  break;  //SLL (IX+*), E
        case 0x34:  z->H(rot->SLL(v));                                                                  break;  //SLL (IX+*), H
        case 0x35:  z->L(rot->SLL(v));                                                                  break;  //SLL (IX+*), L
        case 0x36:  z->mM->set(x, rot->SLL(v));                                                         break;  //SLL (IX+*), 
        case 0x37:  z->A(rot->SLL(v));                                                                  break;  //SLL (IX+*), A
        case 0x38:  z->B(rot->SRL(v));                                                                  break;  //SRL (IX+*), B
        case 0x39:  z->C(rot->SRL(v));                                                                  break;  //SRL (IX+*), C
        case 0x3A:  z->D(rot->SRL(v));                                                                  break;  //SRL (IX+*), D
        case 0x3B:  z->E(rot->SRL(v));                                                                  break;  //SRL (IX+*), E
        case 0x3C:  z->H(rot->SRL(v));                                                                  break;  //SRL (IX+*), H
        case 0x3D:  z->L(rot->SRL(v));                                                                  break;  //SRL (IX+*), L
        case 0x3E:  z->mM->set(x, rot->SRL(v));                                                         break;  //SRL (IX+*), 
        case 0x3F:  z->A(rot->SRL(v));                                                                  break;  //SRL (IX+*), A
        
        case 0x40:  bit->bit(0, v);                                                                     break;  //BIT 0, (IX+*)
        case 0x41:  bit->bit(0, v);                                                                     break;  //BIT 0, (IX+*)
        case 0x42:  bit->bit(0, v);                                                                     break;  //BIT 0, (IX+*)
        case 0x43:  bit->bit(0, v);                                                                     break;  //BIT 0, (IX+*)
        case 0x44:  bit->bit(0, v);                                                                     break;  //BIT 0, (IX+*)
        case 0x45:  bit->bit(0, v);                                                                     break;  //BIT 0, (IX+*)
        case 0x46:  bit->bit(0, z->mM->get(v));                                                         break;  //BIT 0, (IX+*)
        case 0x47:  bit->bit(0, v);                                                                     break;  //BIT 0, (IX+*)
        case 0x48:  bit->bit(1, v);                                                                     break;  //BIT 1, (IX+*)
        case 0x49:  bit->bit(1, v);                                                                     break;  //BIT 1, (IX+*)
        case 0x4A:  bit->bit(1, v);                                                                     break;  //BIT 1, (IX+*)
        case 0x4B:  bit->bit(1, v);                                                                     break;  //BIT 1, (IX+*)
        case 0x4C:  bit->bit(1, v);                                                                     break;  //BIT 1, (IX+*)
        case 0x4D:  bit->bit(1, v);                                                                     break;  //BIT 1, (IX+*)
        case 0x4E:  bit->bit(1, z->mM->get(v));                                                         break;  //BIT 1, (IX+*)
        case 0x4F:  bit->bit(1, v);                                                                     break;  //BIT 1, (IX+*)

        case 0x50:  bit->bit(2, v);                                                                     break;  //BIT 2, (IX+*)
        case 0x51:  bit->bit(2, v);                                                                     break;  //BIT 2, (IX+*)
        case 0x52:  bit->bit(2, v);                                                                     break;  //BIT 2, (IX+*)
        case 0x53:  bit->bit(2, v);                                                                     break;  //BIT 2, (IX+*)
        case 0x54:  bit->bit(2, v);                                                                     break;  //BIT 2, (IX+*)
        case 0x55:  bit->bit(2, v);                                                                     break;  //BIT 2, (IX+*)
        case 0x56:  bit->bit(2, z->mM->get(v));                                                         break;  //BIT 2, (IX+*)
        case 0x57:  bit->bit(2, v);                                                                     break;  //BIT 2, (IX+*)
        case 0x58:  bit->bit(3, v);                                                                     break;  //BIT 3, (IX+*)
        case 0x59:  bit->bit(3, v);                                                                     break;  //BIT 3, (IX+*)
        case 0x5A:  bit->bit(3, v);                                                                     break;  //BIT 3, (IX+*)
        case 0x5B:  bit->bit(3, v);                                                                     break;  //BIT 3, (IX+*)
        case 0x5C:  bit->bit(3, v);                                                                     break;  //BIT 3, (IX+*)
        case 0x5D:  bit->bit(3, v);                                                                     break;  //BIT 3, (IX+*)
        case 0x5E:  bit->bit(3, z->mM->get(v));                                                         break;  //BIT 3, (IX+*)
        case 0x5F:  bit->bit(3, v);                                                                     break;  //BIT 3, (IX+*)

        case 0x60:  bit->bit(4, v);                                                                     break;  //BIT 4, (IX+*)
        case 0x61:  bit->bit(4, v);                                                                     break;  //BIT 4, (IX+*)
        case 0x62:  bit->bit(4, v);                                                                     break;  //BIT 4, (IX+*)
        case 0x63:  bit->bit(4, v);                                                                     break;  //BIT 4, (IX+*)
        case 0x64:  bit->bit(4, v);                                                                     break;  //BIT 4, (IX+*)
        case 0x65:  bit->bit(4, v);                                                                     break;  //BIT 4, (IX+*)
        case 0x66:  bit->bit(4, z->mM->get(v));                                                         break;  //BIT 4, (IX+*)
        case 0x67:  bit->bit(4, v);                                                                     break;  //BIT 4, (IX+*)
        case 0x68:  bit->bit(4, v);                                                                     break;  //BIT 5, (IX+*)
        case 0x69:  bit->bit(5, v);                                                                     break;  //BIT 5, (IX+*)
        case 0x6A:  bit->bit(5, v);                                                                     break;  //BIT 5, (IX+*)
        case 0x6B:  bit->bit(5, v);                                                                     break;  //BIT 5, (IX+*)
        case 0x6C:  bit->bit(5, v);                                                                     break;  //BIT 5, (IX+*)
        case 0x6D:  bit->bit(5, v);                                                                     break;  //BIT 5, (IX+*)
        case 0x6E:  bit->bit(5, z->mM->get(v));                                                         break;  //BIT 5, (IX+*)
        case 0x6F:  bit->bit(5, v);                                                                     break;  //BIT 5, (IX+*)

        case 0x70:  bit->bit(6, v);                                                                     break;  //BIT 6, (IX+*)
        case 0x71:  bit->bit(6, v);                                                                     break;  //BIT 6, (IX+*)
        case 0x72:  bit->bit(6, v);                                                                     break;  //BIT 6, (IX+*)
        case 0x73:  bit->bit(6, v);                                                                     break;  //BIT 6, (IX+*)
        case 0x74:  bit->bit(6, v);                                                                     break;  //BIT 6, (IX+*)
        case 0x75:  bit->bit(6, v);                                                                     break;  //BIT 6, (IX+*)
        case 0x76:  bit->bit(6, z->mM->get(v));                                                         break;  //BIT 6, (IX+*)
        case 0x77:  bit->bit(6, v);                                                                     break;  //BIT 6, (IX+*)
        case 0x78:  bit->bit(7, v);                                                                     break;  //BIT 7, (IX+*)
        case 0x79:  bit->bit(7, v);                                                                     break;  //BIT 7, (IX+*)
        case 0x7A:  bit->bit(7, v);                                                                     break;  //BIT 7, (IX+*)
        case 0x7B:  bit->bit(7, v);                                                                     break;  //BIT 7, (IX+*)
        case 0x7C:  bit->bit(7, v);                                                                     break;  //BIT 7, (IX+*)
        case 0x7D:  bit->bit(7, v);                                                                     break;  //BIT 7, (IX+*)
        case 0x7E:  bit->bit(7, z->mM->get(v));                                                         break;  //BIT 7, (IX+*)
        case 0x7F:  bit->bit(7, v);                                                                     break;  //BIT 7, (IX+*)

        case 0x80:  z->B(bit->res(0, v));   z->mM->set(x, z->B());                                      break;  //RES 0, (IX+*), B
        case 0x81:  z->C(bit->res(0, v));   z->mM->set(x, z->C());                                      break;  //RES 0, (IX+*), C
        case 0x82:  z->D(bit->res(0, v));   z->mM->set(x, z->D());                                      break;  //RES 0, (IX+*), D
        case 0x83:  z->E(bit->res(0, v));   z->mM->set(x, z->E());                                      break;  //RES 0, (IX+*), E
        case 0x84:  z->H(bit->res(0, v));   z->mM->set(x, z->H());                                      break;  //RES 0, (IX+*), H
        case 0x85:  z->L(bit->res(0, v));   z->mM->set(x, z->L());                                      break;  //RES 0, (IX+*), L
        case 0x86:  z->mM->set(x, bit->res(0, v));                                                      break;  //RES 0, (IX+*)
        case 0x87:  z->A(bit->res(0, v));   z->mM->set(x, z->A());                                      break;  //RES 0, (IX+*), A
        case 0x88:  z->B(bit->res(1, v));   z->mM->set(x, z->B());                                      break;  //RES 1, (IX+*), B
        case 0x89:  z->C(bit->res(1, v));   z->mM->set(x, z->C());                                      break;  //RES 1, (IX+*), C
        case 0x8A:  z->D(bit->res(1, v));   z->mM->set(x, z->D());                                      break;  //RES 1, (IX+*), D
        case 0x8B:  z->E(bit->res(1, v));   z->mM->set(x, z->E());                                      break;  //RES 1, (IX+*), E
        case 0x8C:  z->H(bit->res(1, v));   z->mM->set(x, z->H());                                      break;  //RES 1, (IX+*), H
        case 0x8D:  z->L(bit->res(1, v));   z->mM->set(x, z->L());                                      break;  //RES 1, (IX+*), L
        case 0x8E:  z->mM->set(x, bit->res(1, v));                                                      break;  //RES 1, (IX+*)
        case 0x8F:  z->A(bit->res(1, v));   z->mM->set(x, z->A());                                      break;  //RES 1, (IX+*), A
        
        case 0x90:  z->B(bit->res(2, v));   z->mM->set(x, z->B());                                      break;  //RES 2, (IX+*), B
        case 0x91:  z->C(bit->res(2, v));   z->mM->set(x, z->C());                                      break;  //RES 2, (IX+*), C
        case 0x92:  z->D(bit->res(2, v));   z->mM->set(x, z->D());                                      break;  //RES 2, (IX+*), D
        case 0x93:  z->E(bit->res(2, v));   z->mM->set(x, z->E());                                      break;  //RES 2, (IX+*), E
        case 0x94:  z->H(bit->res(2, v));   z->mM->set(x, z->H());                                      break;  //RES 2, (IX+*), H
        case 0x95:  z->L(bit->res(2, v));   z->mM->set(x, z->L());                                      break;  //RES 2, (IX+*), L
        case 0x96:  z->mM->set(x, bit->res(2, v));                                                      break;  //RES 2, (IX+*)
        case 0x97:  z->A(bit->res(2, v));   z->mM->set(x, z->A());                                      break;  //RES 2, (IX+*), A
        case 0x98:  z->B(bit->res(3, v));   z->mM->set(x, z->B());                                      break;  //RES 3, (IX+*), B
        case 0x99:  z->C(bit->res(3, v));   z->mM->set(x, z->C());                                      break;  //RES 3, (IX+*), C
        case 0x9A:  z->D(bit->res(3, v));   z->mM->set(x, z->D());                                      break;  //RES 3, (IX+*), D
        case 0x9B:  z->E(bit->res(3, v));   z->mM->set(x, z->E());                                      break;  //RES 3, (IX+*), E
        case 0x9C:  z->H(bit->res(3, v));   z->mM->set(x, z->H());                                      break;  //RES 3, (IX+*), H
        case 0x9D:  z->L(bit->res(3, v));   z->mM->set(x, z->L());                                      break;  //RES 3, (IX+*), L
        case 0x9E:  z->mM->set(x, bit->res(3, v));                                                      break;  //RES 3, (IX+*)
        case 0x9F:  z->A(bit->res(3, v));   z->mM->set(x, z->A());                                      break;  //RES 3, (IX+*), A

        case 0xA0:  z->B(bit->res(4, v));   z->mM->set(x, z->B());                                      break;  //RES 4, (IX+*), B
        case 0xA1:  z->C(bit->res(4, v));   z->mM->set(x, z->C());                                      break;  //RES 4, (IX+*), C
        case 0xA2:  z->D(bit->res(4, v));   z->mM->set(x, z->D());                                      break;  //RES 4, (IX+*), D
        case 0xA3:  z->E(bit->res(4, v));   z->mM->set(x, z->E());                                      break;  //RES 4, (IX+*), E
        case 0xA4:  z->H(bit->res(4, v));   z->mM->set(x, z->H());                                      break;  //RES 4, (IX+*), H
        case 0xA5:  z->L(bit->res(4, v));   z->mM->set(x, z->L());                                      break;  //RES 4, (IX+*), L
        case 0xA6:  z->mM->set(x, bit->res(4, v));                                                      break;  //RES 4, (IX+*)
        case 0xA7:  z->A(bit->res(4, v));   z->mM->set(x, z->A());                                      break;  //RES 4, (IX+*), A
        case 0xA8:  z->B(bit->res(5, v));   z->mM->set(x, z->B());                                      break;  //RES 5, (IX+*), B
        case 0xA9:  z->C(bit->res(5, v));   z->mM->set(x, z->C());                                      break;  //RES 5, (IX+*), C
        case 0xAA:  z->D(bit->res(5, v));   z->mM->set(x, z->D());                                      break;  //RES 5, (IX+*), D
        case 0xAB:  z->E(bit->res(5, v));   z->mM->set(x, z->E());                                      break;  //RES 5, (IX+*), E
        case 0xAC:  z->H(bit->res(5, v));   z->mM->set(x, z->H());                                      break;  //RES 5, (IX+*), H
        case 0xAD:  z->L(bit->res(5, v));   z->mM->set(x, z->L());                                      break;  //RES 5, (IX+*), L
        case 0xAE:  z->mM->set(x, bit->res(5, v));                                                      break;  //RES 5, (IX+*)
        case 0xAF:  z->A(bit->res(5, v));   z->mM->set(x, z->A());                                      break;  //RES 5, (IX+*), A

        case 0xB0:  z->B(bit->res(6, v));   z->mM->set(x, z->B());                                      break;  //RES 6, (IX+*), B
        case 0xB1:  z->C(bit->res(6, v));   z->mM->set(x, z->C());                                      break;  //RES 6, (IX+*), C
        case 0xB2:  z->D(bit->res(6, v));   z->mM->set(x, z->D());                                      break;  //RES 6, (IX+*), D
        case 0xB3:  z->E(bit->res(6, v));   z->mM->set(x, z->E());                                      break;  //RES 6, (IX+*), E
        case 0xB4:  z->H(bit->res(6, v));   z->mM->set(x, z->H());                                      break;  //RES 6, (IX+*), H
        case 0xB5:  z->L(bit->res(6, v));   z->mM->set(x, z->L());                                      break;  //RES 6, (IX+*), L
        case 0xB6:  z->mM->set(x, bit->res(6, v));                                                      break;  //RES 6, (IX+*)
        case 0xB7:  z->A(bit->res(6, v));   z->mM->set(x, z->A());                                      break;  //RES 6, (IX+*), A
        case 0xB8:  z->B(bit->res(7, v));   z->mM->set(x, z->B());                                      break;  //RES 7, (IX+*), B
        case 0xB9:  z->C(bit->res(7, v));   z->mM->set(x, z->C());                                      break;  //RES 7, (IX+*), C
        case 0xBA:  z->D(bit->res(7, v));   z->mM->set(x, z->D());                                      break;  //RES 7, (IX+*), D
        case 0xBB:  z->E(bit->res(7, v));   z->mM->set(x, z->E());                                      break;  //RES 7, (IX+*), E
        case 0xBC:  z->H(bit->res(7, v));   z->mM->set(x, z->H());                                      break;  //RES 7, (IX+*), H
        case 0xBD:  z->L(bit->res(7, v));   z->mM->set(x, z->L());                                      break;  //RES 7, (IX+*), L
        case 0xBE:  z->mM->set(x, bit->res(7, v));                                                      break;  //RES 7, (IX+*)
        case 0xBF:  z->A(bit->res(7, v));   z->mM->set(x, z->A());                                      break;  //RES 7, (IX+*), A

        case 0xC0:  z->B(bit->set(0, v));   z->mM->set(x, z->B());                                      break;  //SET 0, (IX+*), B
        case 0xC1:  z->C(bit->set(0, v));   z->mM->set(x, z->C());                                      break;  //SET 0, (IX+*), C
        case 0xC2:  z->D(bit->set(0, v));   z->mM->set(x, z->D());                                      break;  //SET 0, (IX+*), D
        case 0xC3:  z->E(bit->set(0, v));   z->mM->set(x, z->E());                                      break;  //SET 0, (IX+*), E
        case 0xC4:  z->H(bit->set(0, v));   z->mM->set(x, z->H());                                      break;  //SET 0, (IX+*), H
        case 0xC5:  z->L(bit->set(0, v));   z->mM->set(x, z->L());                                      break;  //SET 0, (IX+*), L
        case 0xC6:  z->mM->set(x, bit->set(0, v));                                                      break;  //SET 0, (IX+*)
        case 0xC7:  z->A(bit->set(0, v));   z->mM->set(x, z->A());                                      break;  //SET 0, (IX+*), A
        case 0xC8:  z->B(bit->set(1, v));   z->mM->set(x, z->B());                                      break;  //SET 1, (IX+*), B
        case 0xC9:  z->C(bit->set(1, v));   z->mM->set(x, z->C());                                      break;  //SET 1, (IX+*), C
        case 0xCA:  z->D(bit->set(1, v));   z->mM->set(x, z->D());                                      break;  //SET 1, (IX+*), D
        case 0xCB:  z->E(bit->set(1, v));   z->mM->set(x, z->E());                                      break;  //SET 1, (IX+*), E
        case 0xCC:  z->H(bit->set(1, v));   z->mM->set(x, z->H());                                      break;  //SET 1, (IX+*), H
        case 0xCD:  z->L(bit->set(1, v));   z->mM->set(x, z->L());                                      break;  //SET 1, (IX+*), L
        case 0xCE:  z->mM->set(x, bit->set(1, v));                                                      break;  //SET 1, (IX+*)
        case 0xCF:  z->A(bit->set(1, v));   z->mM->set(x, z->A());                                      break;  //SET 1, (IX+*), A

        case 0xD0:  z->B(bit->set(2, v));   z->mM->set(x, z->B());                                      break;  //SET 2, (IX+*), B
        case 0xD1:  z->C(bit->set(2, v));   z->mM->set(x, z->C());                                      break;  //SET 2, (IX+*), C
        case 0xD2:  z->D(bit->set(2, v));   z->mM->set(x, z->D());                                      break;  //SET 2, (IX+*), D
        case 0xD3:  z->E(bit->set(2, v));   z->mM->set(x, z->E());                                      break;  //SET 2, (IX+*), E
        case 0xD4:  z->H(bit->set(2, v));   z->mM->set(x, z->H());                                      break;  //SET 2, (IX+*), H
        case 0xD5:  z->L(bit->set(2, v));   z->mM->set(x, z->L());                                      break;  //SET 2, (IX+*), L
        case 0xD6:  z->mM->set(x, bit->set(2, v));                                                      break;  //SET 2, (IX+*)
        case 0xD7:  z->A(bit->set(2, v));   z->mM->set(x, z->A());                                      break;  //SET 2, (IX+*), A
        case 0xD8:  z->B(bit->set(3, v));   z->mM->set(x, z->B());                                      break;  //SET 3, (IX+*), B
        case 0xD9:  z->C(bit->set(3, v));   z->mM->set(x, z->C());                                      break;  //SET 3, (IX+*), C
        case 0xDA:  z->D(bit->set(3, v));   z->mM->set(x, z->D());                                      break;  //SET 3, (IX+*), D
        case 0xDB:  z->E(bit->set(3, v));   z->mM->set(x, z->E());                                      break;  //SET 3, (IX+*), E
        case 0xDC:  z->H(bit->set(3, v));   z->mM->set(x, z->H());                                      break;  //SET 3, (IX+*), H
        case 0xDD:  z->L(bit->set(3, v));   z->mM->set(x, z->L());                                      break;  //SET 3, (IX+*), L
        case 0xDE:  z->mM->set(x, bit->set(3, v));                                                      break;  //SET 3, (IX+*)
        case 0xDF:  z->A(bit->set(3, v));   z->mM->set(x, z->A());                                      break;  //SET 3, (IX+*), A
        
        case 0xE0:  z->B(bit->set(4, v));   z->mM->set(x, z->B());                                      break;  //SET 4, (IX+*), B
        case 0xE1:  z->C(bit->set(4, v));   z->mM->set(x, z->C());                                      break;  //SET 4, (IX+*), C
        case 0xE2:  z->D(bit->set(4, v));   z->mM->set(x, z->D());                                      break;  //SET 4, (IX+*), D
        case 0xE3:  z->E(bit->set(4, v));   z->mM->set(x, z->E());                                      break;  //SET 4, (IX+*), E
        case 0xE4:  z->H(bit->set(4, v));   z->mM->set(x, z->H());                                      break;  //SET 4, (IX+*), H
        case 0xE5:  z->L(bit->set(4, v));   z->mM->set(x, z->L());                                      break;  //SET 4, (IX+*), L
        case 0xE6:  z->mM->set(x, bit->set(4, v));                                                      break;  //SET 4, (IX+*)
        case 0xE7:  z->A(bit->set(4, v));   z->mM->set(x, z->A());                                      break;  //SET 4, (IX+*), A
        case 0xE8:  z->B(bit->set(5, v));   z->mM->set(x, z->B());                                      break;  //SET 5, (IX+*), B
        case 0xE9:  z->C(bit->set(5, v));   z->mM->set(x, z->C());                                      break;  //SET 5, (IX+*), C
        case 0xEA:  z->D(bit->set(5, v));   z->mM->set(x, z->D());                                      break;  //SET 5, (IX+*), D
        case 0xEB:  z->E(bit->set(5, v));   z->mM->set(x, z->E());                                      break;  //SET 5, (IX+*), E
        case 0xEC:  z->H(bit->set(5, v));   z->mM->set(x, z->H());                                      break;  //SET 5, (IX+*), H
        case 0xED:  z->L(bit->set(5, v));   z->mM->set(x, z->L());                                      break;  //SET 5, (IX+*), L
        case 0xEE:  z->mM->set(x, bit->set(5, v));                                                      break;  //SET 5, (IX+*)
        case 0xEF:  z->A(bit->set(5, v));   z->mM->set(x, z->A());                                      break;  //SET 5, (IX+*), A

        case 0xF0:  z->B(bit->set(6, v));   z->mM->set(x, z->B());                                      break;  //SET 6, (IX+*), B
        case 0xF1:  z->C(bit->set(6, v));   z->mM->set(x, z->C());                                      break;  //SET 6, (IX+*), C
        case 0xF2:  z->D(bit->set(6, v));   z->mM->set(x, z->D());                                      break;  //SET 6, (IX+*), D
        case 0xF3:  z->E(bit->set(6, v));   z->mM->set(x, z->E());                                      break;  //SET 6, (IX+*), E
        case 0xF4:  z->H(bit->set(6, v));   z->mM->set(x, z->H());                                      break;  //SET 6, (IX+*), H
        case 0xF5:  z->L(bit->set(6, v));   z->mM->set(x, z->L());                                      break;  //SET 6, (IX+*), L
        case 0xF6:  z->mM->set(x, bit->set(6, v));                                                      break;  //SET 6, (IX+*)
        case 0xF7:  z->A(bit->set(6, v));   z->mM->set(x, z->A());                                      break;  //SET 6, (IX+*), A
        case 0xF8:  z->B(bit->set(7, v));   z->mM->set(x, z->B());                                      break;  //SET 7, (IX+*), B
        case 0xF9:  z->C(bit->set(7, v));   z->mM->set(x, z->C());                                      break;  //SET 7, (IX+*), C
        case 0xFA:  z->D(bit->set(7, v));   z->mM->set(x, z->D());                                      break;  //SET 7, (IX+*), D
        case 0xFB:  z->E(bit->set(7, v));   z->mM->set(x, z->E());                                      break;  //SET 7, (IX+*), E
        case 0xFC:  z->H(bit->set(7, v));   z->mM->set(x, z->H());                                      break;  //SET 7, (IX+*), H
        case 0xFD:  z->L(bit->set(7, v));   z->mM->set(x, z->L());                                      break;  //SET 7, (IX+*), L
        case 0xFE:  z->mM->set(x, bit->set(7, v));                                                      break;  //SET 7, (IX+*)
        case 0xFF:  z->A(bit->set(7, v));   z->mM->set(x, z->A());                                      break;  //SET 7, (IX+*), A

        default:    log->logUnimplemented(op);                                                          break;  //Not implemented instructions
    }
}