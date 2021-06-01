#include "iSet.h"

ISet::ISet(Z80* z80){
    FUN();
    this->z80 = z80;
    this->mainIS = new MainIS(this->z80);
    this->bitIS = new BitIS(this->z80);
    this->extIS = new ExtIS(this->z80);
}

ISet::~ISet(){
    FUN();

    delete this->mainIS;
    delete this->bitIS;
    delete this->extIS;
}

void ISet::execIS(Z80EmuInstrucion is){
    FUN();

    switch(is[0]){
        case 0xcb:
            LOGD("Executing using BIT instruction set");
            this->bitIS->exec(is);
            break;

        case 0xed:
            LOGD("Executing using EXT instruction set");
            this->extIS->exec(is);
            break;

        default:
            LOGD("Executing using MAIN instruction set");
            this->mainIS->exec(is);
            break;
    }
}