#include "extIS.h"

void ExtIS::exec(Instruction is){
    FUN();

    switch(is[1]){


        case 0x40:  z->B(z->ioManager->in(z->C()));                                             break;      //IN B, (C)
        case 0x41:  z->ioManager->out(z->C(), z->B());                                          break;      //OUT (C), B
        case 0x48:  z->C(z->ioManager->in(z->C()));                                             break;      //IN C, (C)
        case 0x49:  z->ioManager->out(z->C(), z->C());                                          break;      //OUT (C), C


        case 0x50:  z->D(z->ioManager->in(z->C()));                                             break;      //IN D, (C)
        case 0x51:  z->ioManager->out(z->C(), z->D());                                          break;      //OUT (C), D
        case 0x58:  z->E(z->ioManager->in(z->C()));                                             break;      //IN E, (C)
        case 0x59:  z->ioManager->out(z->C(), z->E());                                          break;      //OUT (C), E

        case 0x60:  z->H(z->ioManager->in(z->C()));                                             break;      //IN H, (C)
        case 0x61:  z->ioManager->out(z->C(), z->H());                                          break;      //OUT (C), H
        case 0x68:  z->L(z->ioManager->in(z->C()));                                             break;      //IN L, (C)
        case 0x69:  z->ioManager->out(z->C(), z->L());                                          break;      //OUT (C), L

        case 0x70:  z->ioManager->in(z->C());                                                   break;      //IN (C)
        case 0x71:  z->ioManager->out(z->C(), 0);                                               break;      //OUT (C), 0
        case 0x78:  z->A(z->ioManager->in(z->C()));                                             break;      //IN A, (C)
        case 0x79:  z->ioManager->out(z->C(), z->A());                                          break;      //OUT (C), A

        default:
            LOGE("Unimplemented opcode: " + Log::toHexString(is[1]));
            break;
    }
}