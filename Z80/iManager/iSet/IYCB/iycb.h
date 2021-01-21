#ifndef __IYCB_H__
#define __IYCB_H__

class IYCB;

#include "../../../log/log.h"
#include "../../../../z80.h"

#include "../rotate/rotate.h"
#include "../bit/bit.h"

class IYCB{

public:
    IYCB(Z80* z80);

    void exec(uint8_t* opcode);          //These instructions don't have any operands!

    uint8_t getCycles(uint8_t);

private:
    Z80* z;
    Log* log;

    Rotate* rot;
    Bit* bit;

};

#endif