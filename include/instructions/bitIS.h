#ifndef __BITIS_H__
#define __BITIS_H__

class BitIS;

#include "log.h"
#include "z80emu.h"

#include "z80emuinstruction.h"

#include "cpufunctions/rotate.h"
#include "cpufunctions/bit.h"

class BitIS{
public:
    BitIS(Z80* z80);
    ~BitIS();

    void                                fetch(Z80EmuInstrucion&);

    void                                exec(Z80EmuInstrucion);

private:
    Z80*                                z;

    Rotate*                             rot;
    Bit*                                bit;

    void                                p_fillArrays();
    uint8_t*                            _opCycles;
};

#endif