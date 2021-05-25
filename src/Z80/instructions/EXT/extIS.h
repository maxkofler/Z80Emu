#ifndef __EXT_IS_H__
#define __EXT_IS_H__

class ExtIS;

#include "../../log/log.h"
#include "../../z80.h"
#include "../../cpu/instruction/instruction.h"

class ExtIS{

public:
    ExtIS(Z80*);
    ~ExtIS();

    void                            fetch(Instruction&);

    void                            exec(Instruction);

private:
    Z80*                            z;

    void                            p_fillArrays();
    uint8_t*                        _opBytes;
    uint8_t*                        _opCycles;
};

#endif