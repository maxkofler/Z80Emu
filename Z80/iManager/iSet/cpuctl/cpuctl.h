#ifndef __CPUCTL_H__
#define __CPUCTL_H__

class CPUctl;

#include "../../../log/log.h"
#include "../../../../z80.h"

class CPUctl{
public:
    CPUctl(Z80*);

private:
    Z80* z80;
};

#endif