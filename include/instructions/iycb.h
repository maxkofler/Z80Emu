#ifndef __IYCB_H__
#define __IYCB_H__

class IYCB;

#include "log.h"
#include "z80.h"

#include "instruction.h"
#include "cpufunctions/rotate.h"
#include "cpufunctions/bit.h"

class IYCB{

public:
    IYCB(Z80* z80);
    ~IYCB();

    void                            fetch(Instruction&);

    void                            exec(Instruction);

private:
    Z80*                            z;

    Rotate*                         rot;
    Bit*                            bit;

    void                            p_fillArrays();
    uint8_t*                        _opCycles;
};

#endif