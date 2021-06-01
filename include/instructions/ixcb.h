#ifndef __IXCB_H__
#define __IXCB_H__

class IXCB;

#include "log.h"
#include "z80emu.h"

#include "z80emuinstruction.h"
#include "cpufunctions/rotate.h"
#include "cpufunctions/bit.h"

class IXCB{

public:
    IXCB(Z80* z80);
    ~IXCB();

    void                        fetch(Z80EmuInstrucion&);

    void                        exec(Z80EmuInstrucion);          //These instructions don't have any operands!

private:
    Z80* z;

    Rotate* rot;
    Bit* bit;

    void                        p_fillArrays();
    uint8_t*                    _opCycles;
};

#endif