#ifndef __ROTATE_H__
#define __ROTATE_H__

class Rotate;

#include "../../z80.h"

class Rotate{
public:
    Rotate(Z80*);

    //Rotates left 1 bit, bit 7 will be copied to carry and bit 0
    uint8_t RLC(uint8_t);
    //Rotates left 1 bit, carry will be copied to bit 0 and bit 7 into carry
    uint8_t RL(uint8_t);

    //Rotates right 1 bit, bit 0 will be copied to carry and bit 7
    uint8_t RRC(uint8_t);
    //Rotates right 1 bit, carry will be copied to bit 7 and bit 0 to carry
    uint8_t RR(uint8_t);

    uint8_t     SRA     (uint8_t reg);
    uint8_t     SRL     (uint8_t reg);

    uint8_t     SLA     (uint8_t reg);
    uint8_t     SLL     (uint8_t reg);

private:
    Z80* z80;
};

#endif