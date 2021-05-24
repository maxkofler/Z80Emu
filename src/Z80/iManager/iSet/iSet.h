#ifndef __ISET_H__
#define __ISET_H__

class ISet;

#include "../../z80.h"
#include "../../log/log.h"

#include "../../cpu/instruction/instruction.h"
#include "../../instructions/MAINIS/mainIs.h"
#include "../../instructions/BIT/bitIS.h"

#include <stdint.h>

class ISet{

public:
    ISet(Z80*);

    //New function to fetch all the instruction data from memory
    Instruction             fetchInstruction(uint8_t opcode);

    //Execute the instruction specified
    void                    execIS(Instruction is);

private:
    Z80* z80;

    MainIS* mainIS;
    BitIS* bitIS;

    uint8_t *opBytes;
};

#endif