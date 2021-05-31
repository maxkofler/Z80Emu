#ifndef __CPUCTL_H__
#define __CPUCTL_H__

class CPUctl;

#include "log.h"
#include "z80.h"

class CPUctl{
public:
    CPUctl(Z80*);

    //If condition is true, ** wil be returned and so copied into PC
    uint16_t    jp      (bool condition, uint16_t position);
    
    //If condition is true, *(offset - signed) will be added to PC
    //and then copied to PC
    uint16_t    jr      (bool condition, uint8_t offset);


    //If condition is true, the current PC and three are pushed to the stack
    //and **(position) will be returned and then copied to PC
    uint16_t    call    (bool condition, uint16_t position);

    //If condition is true, the top stack entry is popped into PC
    uint16_t    ret     (bool condition);

    //SP is decremented, value(first 8bit) will be stored in location pointed by SP,
    //SP is decremented again and the same procedure follows with value(last 8bit)
    void        push    (uint16_t value);

    //First 8bit are being read from memory pointed by SP, than SP is getting incremented,
    //Then the same with the next 8bit
    uint16_t    pop     ();

    //Current PC value plus one is pushed on stack, then is loaded with new_value
    void        rst     (uint8_t new_value);

    //Exchanges the two 16bit values of reg1 and reg2
    void        ex      (uint8_t* reg1a, uint8_t* reg2a, uint8_t* reg1b, uint8_t* reg2b);

    //Exchanges the values of the primary and shadow registers
    void        exx     ();

private:
    Z80* z80;
};

#endif