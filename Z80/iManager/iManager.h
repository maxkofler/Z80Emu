#ifndef __IMANAGER_H__
#define __IMANAGER_H__

#include <stdint.h>

class Z80;

#include "iSet/iSet.h"
#include "../../z80.h"
#include "../log/log.h"

class IManager{

public:
    IManager(Z80*, Log*);

    uint8_t* fetchIS(uint16_t);
    void execIS();

private:
    uint8_t* curIS;
    ISet* iSet;
    Z80* z80;
    Log* log;
};

//#include "iManager.cpp"
#endif