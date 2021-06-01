#ifndef __EXT_IS_H__
#define __EXT_IS_H__

class ExtIS;

#include "log.h"
#include "z80emu.h"
#include "z80emuinstruction.h"

class ExtIS{

public:
    ExtIS(Z80*);
    ~ExtIS();

    void                            fetch(Z80EmuInstrucion&);

    void                            exec(Z80EmuInstrucion);

private:
    Z80*                            z;

    void                            p_fillArrays();
    uint8_t*                        _opBytes;
    uint8_t*                        _opCycles;
};

#endif