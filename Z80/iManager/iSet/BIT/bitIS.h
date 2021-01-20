#ifndef __BITIS_H__
#define __BITIS_H__

class BitIS;

#include "../../../log/log.h"
#include "../../../../z80.h"

#include "../rotate/rotate.h"

class BitIS{
public:
    BitIS(Z80* z80, Log* log);

    void exec(uint8_t opcode);          //These instructions don't have any operands!

    uint8_t getCycles(uint8_t);

private:
    Z80* z;
    Log* log;

    Rotate* rot;
};

#endif