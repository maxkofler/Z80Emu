#ifndef __INCDECADDSUB_H__
#define __INCDECADDSUB_H__

#include "../../z80.h"
#include <stdint.h>

//Inherited from Z80 class to access flags

class IncDecAddSub{

public:
    IncDecAddSub(Z80*);

    uint8_t inc(uint8_t);
    uint16_t incX16(uint16_t);

    uint8_t dec(uint8_t);
    uint16_t decX16(uint16_t);

    uint8_t add(uint8_t, uint8_t);
    
    uint8_t sub(uint8_t, uint8_t);

private:
    Z80* z80;
};

#include "incdecaddsub.cpp"

#endif