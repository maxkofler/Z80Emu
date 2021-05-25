#include "extIS.h"

void ExtIS::exec(Instruction is){
    FUN();

    switch(is[1]){
        default:
            LOGE("Unimplemented opcode: " + Log::toHexString(is[1]));
            break;
    }
}