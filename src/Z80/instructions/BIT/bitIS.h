#ifndef __BITIS_H__
#define __BITIS_H__

class BitIS;

#include "../../log/log.h"
#include "../../z80.h"

#include "../../cpu/instruction/instruction.h"

#include "../../cpufunctions/rotate/rotate.h"
#include "../../cpufunctions/bit/bit.h"

class BitIS{
public:
    BitIS(Z80* z80);
    ~BitIS();

    void                                fetch(Instruction&);

    void                                exec(Instruction);

private:
    Z80*                                z;

    Rotate*                             rot;
    Bit*                                bit;

    void                                p_fillArrays();
    uint8_t*                            _opCycles;
};

#endif