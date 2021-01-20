#ifndef __CPUCTL_H__
#define __CPUCTL_H__

class CPUctl;

#include "../../../log/log.h"
#include "../../../../z80.h"

class CPUctl{
public:
    CPUctl(Z80*);

    uint16_t    jp      (bool condition, uint16_t position);
    uint16_t    jr      (bool condition, uint8_t offset);

    uint16_t    call    (bool condition, uint16_t position);
    uint16_t    ret     (bool condition);

    void        push    (uint16_t value);
    uint16_t    pop     ();

    void        rst     (uint16_t new_value);

    void        ex      (uint16_t* reg1, uint16_t* reg2);
    void        exx     ();

private:
    Z80* z80;
};

#endif