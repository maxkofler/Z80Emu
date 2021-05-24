#include "iSet.h"

ISet::ISet(Z80* z80){
    FUN();
    this->z80 = z80;
    this->mainIS = new MainIS(this->z80);
    this->bitIS = new BitIS(this->z80);
}

void ISet::execIS(Instruction is){
    FUN();

    if (is[0] == 0xCB){
        LOGD("Executing instruction from Bit instruction set");
        this->bitIS->exec(is);
    }
    else{
        LOGD("Executing instruction from Main instruction set");
        this->mainIS->exec(is);
    }
}