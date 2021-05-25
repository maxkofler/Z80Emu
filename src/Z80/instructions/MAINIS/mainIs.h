#ifndef __MAINIS_H__
#define __MAINIS_H__

class MainIS;

#include "../../z80.h"
#include "../../log/log.h"

#include "../../cpu/instruction/instruction.h"

#include "../../cpufunctions/rotate/rotate.h"
#include "../../cpufunctions/arithmetic/arithmetic.h"
#include "../../cpufunctions/incdecaddsub/incdecaddsub.h"
#include "../../cpufunctions/cpuctl/cpuctl.h"

#include <stdint.h>

class MainIS{
public:
    MainIS(Z80*);
    ~MainIS();

    //Fetches the operands for the provided instruction
    void                        fetch(Instruction& instruction);

    //Executes the provided instruction
    void                        exec(Instruction is);

private:
    IncDecAddSub* idas;
    Rotate* rot;
    Arithmetic* arit;
    CPUctl* cpctl;

    Z80* z;

    void                        p_fillArrays();

    uint8_t*                    _opBytes;
    uint8_t*                    _opCycles;
};

#endif