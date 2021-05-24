#ifndef __ARITHMETIC_H__
#define __ARITHMETIC_H__

class Arithmetic;
#include "../../z80.h"
#include "../incdecaddsub/incdecaddsub.h"
#include <stdint.h>

class Arithmetic{
public:
    Arithmetic(Z80*);

    //Bitwise operations
    uint8_t AND(uint8_t reg1, uint8_t reg2);
    uint8_t OR(uint8_t reg1, uint8_t reg2);
    uint8_t XOR(uint8_t reg1, uint8_t reg2);

    //substracts reg2 from reg1, results are thrown away
    void CP(uint8_t reg1, uint8_t reg2);

private:
    Z80* z80;
    IncDecAddSub* idas;
};

#endif