#ifndef __MAINIS_H__
#define __MAINIS_H__

class MainIS;

#include "../../z80.h"
#include "../../log/log.h"

#include "../../cpufunctions/rotate/rotate.h"
#include "../../cpufunctions/arithmetic/arithmetic.h"
#include "../../cpufunctions/incdecaddsub/incdecaddsub.h"
#include "../../cpufunctions/cpuctl/cpuctl.h"

#include <stdint.h>

class MainIS{
public:
    MainIS(Z80*);
    uint8_t getCycles(uint8_t);
    void exec(uint8_t* is);

private:
    IncDecAddSub* idas;
    Rotate* rot;
    Arithmetic* arit;
    CPUctl* cpctl;

    Z80* z;

    uint8_t* cycles;
};

#endif