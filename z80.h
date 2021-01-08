/*
    -----Z80-----
*/

#ifndef __Z80_H__
#define __Z80_H__

#include <string>
#include <stdint.h>

class IManager;
class MemoryManager;

#include "Z80/memoryManager/memoryManager.h"
#include "Z80/iManager/iManager.h"
#include "Z80/log/log.h"

class Z80{
    
public:
    Z80(int);

    MemoryManager* memoryManager;
    IManager* iManager;

    void sSf(bool x){this->Sf = x;}
    void sZf(bool x){this->Zf = x;}
    void sF5(bool x){this->F5 = x;}
    void sHf(bool x){this->Hf = x;}
    void sF3(bool x){this->F3 = x;}
    void sPVf(bool x){this->PVf = x;}
    void sNf(bool x){this->Nf = x;}
    void sCf(bool x){this->Cf = x;}

    bool gSf(){return this->Sf;}
    bool gZf(){return this->Zf;}
    bool gF5(){return this->F5;}
    bool gHf(){return this->Hf;}
    bool gF3(){return this->F3;}
    bool gPVf(){return this->PVf;}
    bool gNf(){return this->Nf;}
    bool gCf(){return this->Cf;}

private:
    Log* log;

    //Main registers
    uint8_t rA;
    uint8_t rB;
    uint8_t rC;
    uint8_t rD;
    uint8_t rE;
    uint8_t rH;
    uint8_t rL;

    //Shadow registers
    uint8_t rAx;
    uint8_t rBx;
    uint8_t rCx;
    uint8_t rDx;
    uint8_t rEx;
    uint8_t rHx;
    uint8_t rLx;

    //Interrupt vector
    uint8_t rI;
    //Refresh counter
    uint8_t rR;

    //Index registers
    uint16_t IX;
    uint16_t IY;
    uint16_t SP;

    //Program Counter
    uint16_t PC;

    //Flags
    bool Sf;    //Sign flag
    bool Zf;    //Zero flag
    bool F5;    //copy of bit 5
    bool Hf;    //Half carry-flag
    bool F3;    //copy of bit 3
    bool PVf;   //Parity/Overflow
    bool Nf;    //Negative flag
    bool Cf;    //Carry flag
};

#include "Z80/z80.cpp"
#endif