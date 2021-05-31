#ifndef __BIT_H__
#define __BIT_H__

class Bit;

#include "z80emu.h"

class Bit{

public:
    Bit(Z80* z80);

    //Tests bit (pos) of (reg), sets Z flag if bit is not set
    void bit(uint8_t pos, uint8_t reg);
    void bit(uint8_t pos, uint16_t reg);

    //Resets bit (pos) of (reg)
    uint8_t res(uint8_t pos, uint8_t reg);
    uint16_t res(uint8_t pos, uint16_t reg);

    //Sets bit (pos) of (reg)
    uint8_t set(uint8_t pos, uint8_t reg);
    uint16_t set(uint8_t pos, uint16_t reg);

private:
    Z80* z80;

};

#endif