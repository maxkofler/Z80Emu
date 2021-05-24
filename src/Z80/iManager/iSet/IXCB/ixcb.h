#ifndef __IXCB_H__
#define __IXCB_H__

class IXCB;

#include "../../../log/log.h"
#include "../../../../z80.h"

#include "../rotate/rotate.h"
#include "../bit/bit.h"

class IXCB{

public:
    IXCB(Z80* z80);

    void exec(uint8_t* opcode);          //These instructions don't have any operands!

    uint8_t getCycles(uint8_t);

private:
    Z80* z;

    Rotate* rot;
    Bit* bit;

    uint8_t* cycles;
};

#endif