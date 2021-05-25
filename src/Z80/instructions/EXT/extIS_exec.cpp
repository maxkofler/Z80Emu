#include "extIS.h"

void ExtIS::exec(Instruction is){
    FUN();

    switch(is[1]){


        case 0x40:  z->B(z->ioManager->in(z->C()));                                             break;      //IN B, (C)
        case 0x41:  z->ioManager->out(z->C(), z->B());                                          break;      //OUT (C), B

        case 0x50:  z->D(z->ioManager->in(z->C()));                                             break;      //IN D, (C)
        case 0x51:  z->ioManager->out(z->C(), z->D());                                          break;      //OUT (C), D

        case 0x60:  z->H(z->ioManager->in(z->C()));                                             break;      //IN H, (C)
        case 0x61:  z->ioManager->out(z->C(), z->H());                                          break;      //OUT (C), H

        case 0x70:  z->ioManager->in(z->C());                                                   break;      //IN (C)
        case 0x71:  z->ioManager->out(z->C(), 0);                                               break;      //OUT (C), 0

        default:
            LOGE("Unimplemented opcode: " + Log::toHexString(is[1]));
            break;
    }
}