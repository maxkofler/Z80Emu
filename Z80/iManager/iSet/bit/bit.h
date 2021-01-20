#ifndef __BIT_H__
#define __BIT_H__

class Bit;

#include "../../../../z80.h"

class Bit{

public:
    Bit(Z80* z80);

    void bit(uint8_t pos, uint8_t reg);
    void bit(uint8_t pos, uint16_t reg);

    uint8_t res(uint8_t pos, uint8_t reg);
    uint16_t res(uint8_t pos, uint16_t reg);

    uint8_t set(uint8_t pos, uint8_t reg);
    uint16_t set(uint8_t pos, uint16_t reg);

private:
    Z80* z80;

};

#endif