#ifndef __ARITHMETIC_H__
#define __ARITHMETIC_H__

class Arithmetic;
#include "../../../../z80.h"
#include <stdint.h>

class Arithmetic{
public:
    Arithmetic(Z80*);

    uint8_t AND(uint8_t, uint8_t);
    uint8_t OR(uint8_t, uint8_t);

    uint8_t XOR(uint8_t, uint8_t);

    void CP(uint8_t, uint8_t);

private:
    Z80* z80;
};

#endif