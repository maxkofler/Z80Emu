#ifndef __ISET_H__
#define __ISET_H__

class ISet;

#include "z80.h"
#include "log.h"

#include "instruction.h"

#include "instructions/mainIs.h"
#include "instructions/bitIS.h"
#include "instructions/extIS.h"

#include <stdint.h>

class ISet{

public:
    ISet(Z80*);
    ~ISet();

    //New function to fetch all the instruction data from memory
    Instruction             fetchInstruction(uint8_t opcode);

    //Execute the instruction specified
    void                    execIS(Instruction is);

private:
    Z80* z80;

    MainIS*                 mainIS;
    BitIS*                  bitIS;
    ExtIS*                  extIS;

    uint8_t *opBytes;
};

#endif