#ifndef __MAINIS_H__
#define __MAINIS_H__

class MainIS;

#include "../../../../z80.h"
#include "../../../log/log.h"
#include "../rotate/rotate.h"
#include "../arithmetic/arithmetic.h"
#include "../incdecaddsub/incdecaddsub.h"
#include <stdint.h>

class MainIS{
public:
    MainIS(Z80*, Log*);
    uint8_t getCycles(uint8_t);
    void exec(uint8_t* is);

private:
    IncDecAddSub* idas;
    Rotate* rot;
    Arithmetic* arit;
    Z80* z;
    Log* log;

    uint8_t cycles[16] = {
        4, 10, 7, 6, 4, 4, 7, 4, 4, 11, 7, 6, 4, 4, 7, 4
    };
};

#endif