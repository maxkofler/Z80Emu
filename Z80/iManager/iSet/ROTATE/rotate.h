#ifndef __ROTATE_H__
#define __ROTATE_H__

#include "../../../z80.h"

class Rotate{
public:
    Rotate(Z80*);

    uint8_t RLC(uint8_t);
    uint8_t RL(uint8_t);

    uint8_t RRC(uint8_t);
    uint8_t RR(uint8_t);

private:
    Z80* z80;
};

#endif