#include "extIS.h"

void ExtIS::exec(Instruction is){
    FUN();

    switch(is[1]){


        case 0x40:  

        default:
            LOGE("Unimplemented opcode: " + Log::toHexString(is[1]));
            break;
    }
}