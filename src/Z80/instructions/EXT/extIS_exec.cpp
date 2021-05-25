#include "extIS.h"

#include "../../cpufunctions/incdecaddsub/incdecaddsub.h"

void ExtIS::exec(Instruction is){
    FUN();

    IncDecAddSub idas(this->z);

    switch(is[1]){

        case 0x40:  z->B(z->ioManager->in(z->C()));                                             break;      //IN B, (C)
        case 0x41:  z->ioManager->out(z->C(), z->B());                                          break;      //OUT (C), B
        case 0x42:  z->HL(idas.sbcX16(z->HL(), z->BC()));                                       break;      //SBC HL, BC
        case 0x43:  z->mM->setX16(z->getX16(is[3], is[2]), z->BC());                            break;      //LD (**), BC

        case 0x48:  z->C(z->ioManager->in(z->C()));                                             break;      //IN C, (C)
        case 0x49:  z->ioManager->out(z->C(), z->C());                                          break;      //OUT (C), C
        case 0x4a:  z->HL(idas.adcX16(z->HL(), z->BC()));                                       break;      //ADC HL, BC
        case 0x4b:  z->BC(z->mM->getX16(z->getX16(is[3], is[2])));                              break;      //LD BC, (**)




        case 0x50:  z->D(z->ioManager->in(z->C()));                                             break;      //IN D, (C)
        case 0x51:  z->ioManager->out(z->C(), z->D());                                          break;      //OUT (C), D
        case 0x52:  z->HL(idas.sbcX16(z->HL(), z->DE()));                                       break;      //SBC HL, DE
        case 0x53:  z->mM->setX16(z->getX16(is[3], is[2]), z->DE());                            break;      //LD (**), DE

        case 0x58:  z->E(z->ioManager->in(z->C()));                                             break;      //IN E, (C)
        case 0x59:  z->ioManager->out(z->C(), z->E());                                          break;      //OUT (C), E
        case 0x5a:  z->HL(idas.adcX16(z->HL(), z->DE()));                                       break;      //ADC HL, DE
        case 0x5b:  z->DE(z->mM->getX16(z->getX16(is[3], is[2])));                              break;      //LD DE, (**)




        case 0x60:  z->H(z->ioManager->in(z->C()));                                             break;      //IN H, (C)
        case 0x61:  z->ioManager->out(z->C(), z->H());                                          break;      //OUT (C), H
        case 0x62:  z->HL(idas.sbcX16(z->HL(), z->HL()));                                       break;      //SBC HL, HL
        case 0x63:  z->mM->setX16(z->getX16(is[3], is[2]), z->HL());                            break;      //LD (**), HL

        case 0x68:  z->L(z->ioManager->in(z->C()));                                             break;      //IN L, (C)
        case 0x69:  z->ioManager->out(z->C(), z->L());                                          break;      //OUT (C), L
        case 0x6a:  z->HL(idas.adcX16(z->HL(), z->HL()));                                       break;      //ADC HL, HL
        case 0x6b:  z->HL(z->mM->getX16(z->getX16(is[3], is[2])));                              break;      //LD HL, (**)




        case 0x70:  z->ioManager->in(z->C());                                                   break;      //IN (C)
        case 0x71:  z->ioManager->out(z->C(), 0);                                               break;      //OUT (C), 0
        case 0x72:  z->HL(idas.sbcX16(z->HL(), z->SP()));                                       break;      //SBC HL, SP
        case 0x73:  z->mM->setX16(z->getX16(is[3], is[2]), z->SP());                            break;      //LD (**), SP

        case 0x78:  z->A(z->ioManager->in(z->C()));                                             break;      //IN A, (C)
        case 0x79:  z->ioManager->out(z->C(), z->A());                                          break;      //OUT (C), A
        case 0x7a:  z->HL(idas.adcX16(z->HL(), z->SP()));                                       break;      //ADC HL, SP
        case 0x7b:  z->SP(z->mM->getX16(z->getX16(is[3], is[2])));                              break;      //LD SP, (**)

        default:
            LOGE("Unimplemented opcode: " + Log::toHexString(is[1]));
            break;
    }
}