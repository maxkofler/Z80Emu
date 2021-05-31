#ifndef __IMANAGER_H__
#define __IMANAGER_H__

#include <string>
#include <stdint.h>

class IManager;
class Z80;

#include "instruction.h"
#include "iSet.h"
#include "z80.h"
#include "log.h"

class IManager{

public:
    IManager(Z80*);
    ~IManager();

    Instruction                     fetchIS();
    void                            execIS(Instruction is);
    void                            finalizeIS(Instruction is);

    void                            logIS(Instruction is);

private:
    bool ISLoaded;
    uint8_t opcode;
    ISet* iSet;
    Z80* z80;
};

#endif