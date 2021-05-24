#ifndef __IMANAGER_H__
#define __IMANAGER_H__

#include <string>
#include <stdint.h>

class IManager;
class Z80;

#include "iSet/iSet.h"
#include "../../z80.h"
#include "../log/log.h"

class IManager{

public:
    IManager(Z80*);

    uint8_t* fetchIS();
    void execIS(uint8_t*);
    void finalizeIS(uint8_t*);

    void logIS(uint8_t*);

private:
    bool ISLoaded;
    uint8_t opcode;
    ISet* iSet;
    Z80* z80;
};

#endif