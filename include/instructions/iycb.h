#ifndef __IYCB_H__
#define __IYCB_H__

class IYCB;

#include "log.h"
#include "z80emu.h"

#include "z80emuinstruction.h"
#include "cpufunctions/rotate.h"
#include "cpufunctions/bit.h"

class IYCB{

public:
    IYCB(Z80* z80);
    ~IYCB();

    void                            fetch(Z80EmuInstrucion&);

    void                            exec(Z80EmuInstrucion);

private:
    Z80*                            z;

    Rotate*                         rot;
    Bit*                            bit;

    void                            p_fillArrays();
    uint8_t*                        _opCycles;
};

#endif