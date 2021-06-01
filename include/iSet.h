#ifndef __ISET_H__
#define __ISET_H__

class ISet;

#include "z80emu.h"
#include "log.h"

#include "z80emuinstruction.h"

#include "instructions/mainIs.h"
#include "instructions/bitIS.h"
#include "instructions/extIS.h"

#include <stdint.h>

class ISet{

public:
    ISet(Z80*);
    ~ISet();

    //New function to fetch all the instruction data from memory
    Z80EmuInstrucion             fetchZ80EmuInstrucion(uint8_t opcode);

    //Execute the instruction specified
    void                    execIS(Z80EmuInstrucion is);

private:
    Z80* z80;

    MainIS*                 mainIS;
    BitIS*                  bitIS;
    ExtIS*                  extIS;

    uint8_t *opBytes;
};

#endif