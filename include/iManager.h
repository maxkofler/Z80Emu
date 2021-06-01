#ifndef __IMANAGER_H__
#define __IMANAGER_H__

#include <string>
#include <stdint.h>

class IManager;
class Z80;

#include "z80emuinstruction.h"
#include "iSet.h"
#include "z80emu.h"
#include "log.h"

class IManager{

public:
    IManager(Z80*);
    ~IManager();

    Z80EmuInstrucion                     fetchIS();
    void                            execIS(Z80EmuInstrucion is);
    void                            finalizeIS(Z80EmuInstrucion is);

    void                            logIS(Z80EmuInstrucion is);

private:
    bool ISLoaded;
    uint8_t opcode;
    ISet* iSet;
    Z80* z80;
};

#endif