#ifndef __ISET_H__
#define __ISET_H__

#include "../../../z80.h"
#include <stdint.h>

class ISet{

public:
    ISet(Z80*);

    //To get how many bytes of operators this IS needs
    uint8_t getOPBytes(uint8_t);

    //Execute the instruction specified
    void execIS(uint8_t*);

    //Get how many CPU cycles the IS needed
    uint8_t getISCycles(uint8_t);

private:
    Z80* z80;

};

#include "iSet.cpp"

#endif