/*
    -----Z80-----
*/

#ifndef __Z80_H__
#define __Z80_H__

#include <string>
#include <stdint.h>
#include <iostream>

class IManager;
class MemoryManager;

#include "Z80/memoryManager/memoryManager.h"
#include "Z80/iManager/iManager.h"
#include "Z80/log/log.h"

class Z80{
    
public:
    Z80(int);

    MemoryManager* mM;
    IManager* iManager;

    uint8_t A(){return this->rA;}
    uint8_t B(){return this->rB;}
    uint8_t C(){return this->rC;}
    uint8_t D(){return this->rD;}
    uint8_t E(){return this->rE;}
    uint8_t H(){return this->rH;}
    uint8_t L(){return this->rL;}

    void A(uint8_t v){this->rA = v;}
    void B(uint8_t v){this->rB = v;}
    void C(uint8_t v){this->rC = v;}
    void D(uint8_t v){this->rD = v;}
    void E(uint8_t v){this->rE = v;}
    void H(uint8_t v){this->rH = v;}
    void L(uint8_t v){this->rL = v;}

    uint16_t BC(){return this->getX16(this->rC, this->rB);}
    uint16_t DE(){return this->getX16(this->rE, this->rD);}
    uint16_t HL(){return this->getX16(this->rL, this->rH);}

    void BC(uint16_t);
    void DE(uint16_t);
    void HL(uint16_t);

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

    uint64_t addCycles(uint64_t c){this->cycles += c; return this->cycles;}

    uint16_t getX16(uint8_t, uint8_t);

    void logReg();

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

    //Counter for CPU cycles
    uint64_t cycles;
};
#endif