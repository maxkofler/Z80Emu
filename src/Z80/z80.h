#ifndef __Z80_H__
#define __Z80_H__

class Z80;

#include <string>
#include <stdint.h>
#include <iostream>

class IManager;
class MemoryManager;

#include "memoryManager/memoryManager.h"
#include "iManager/iManager.h"
#include "log/log.h"

class Z80{
    
public:
    Z80();
    ~Z80();

    MemoryManager* mM;
    IManager* iManager;

    //Get the contents of registers
    uint8_t A(){return this->rA;}
    uint8_t B(){return this->rB;}
    uint8_t C(){return this->rC;}
    uint8_t D(){return this->rD;}
    uint8_t E(){return this->rE;}
    uint8_t H(){return this->rH;}
    uint8_t L(){return this->rL;}

    //Set the contents of registers
    void A(uint8_t v){this->rA = v;}
    void B(uint8_t v){this->rB = v;}
    void C(uint8_t v){this->rC = v;}
    void D(uint8_t v){this->rD = v;}
    void E(uint8_t v){this->rE = v;}
    void H(uint8_t v){this->rH = v;}
    void L(uint8_t v){this->rL = v;}

    //Get pointer to register
    uint8_t* pA(){return &this->rA;}
    uint8_t* pB(){return &this->rB;}
    uint8_t* pC(){return &this->rC;}
    uint8_t* pD(){return &this->rD;}
    uint8_t* pE(){return &this->rE;}
    uint8_t* pH(){return &this->rH;}
    uint8_t* pL(){return &this->rL;}

    //Get pointer to shadow register
    uint8_t* pAx(){return &this->rAx;}
    uint8_t* pBx(){return &this->rBx;}
    uint8_t* pCx(){return &this->rCx;}
    uint8_t* pDx(){return &this->rDx;}
    uint8_t* pEx(){return &this->rEx;}
    uint8_t* pHx(){return &this->rHx;}
    uint8_t* pLx(){return &this->rLx;}

    //Get 16bit register
    uint16_t BC(){return this->getX16(this->rB, this->rC);}
    uint16_t DE(){return this->getX16(this->rD, this->rE);}
    uint16_t HL(){return this->getX16(this->rH, this->rL);}

    //Set 16bit register
    void BC(uint16_t);
    void DE(uint16_t);
    void HL(uint16_t);

    //Write flag
    void SF(bool x){this->Sf = x;}
    void ZF(bool x){this->Zf = x;}
    void F5F(bool x){this->F5 = x;}
    void HF(bool x){this->Hf = x;}
    void F3F(bool x){this->F3 = x;}
    void PVF(bool x){this->PVf = x;}
    void NF(bool x){this->Nf = x;}
    void CF(bool x){this->Cf = x;}

    //Read flag
    bool SF(){return this->Sf;}
    bool ZF(){return this->Zf;}
    bool F5F(){return this->F5;}
    bool HF(){return this->Hf;}
    bool F3F(){return this->F3;}
    bool PVF(){return this->PVf;}
    bool NF(){return this->Nf;}
    bool CF(){return this->Cf;}

    //Read from memory the PC currently points at
    uint8_t readFromPC();
    //Same as readFromPC, but PC gets incremented after read
    uint8_t readFromPCInc();

    //Query and set HALT state of the CPU
    void HALT(bool v){this->isHalt = v;}
    bool HALT(){return this->isHalt;}

    //Query and set program counter
    uint16_t PC(){return this->rPC;}
    void PC(uint16_t v){this->rPC = v;}

    //Query and set stack pointer
    uint16_t SP(){return this->rSP;}
    void SP(uint16_t v){this->rSP = v;}

    //Query and set IX pointer register
    uint16_t IX(){return this->rIX;}
    void IX(uint16_t v){this->rIX = v;}

    //Query and set IY pointer register
    uint16_t IY(){return this->rIX;}
    void IY(uint16_t v){this->rIX = v;}

    //Add cycles to the cycle counter
    uint64_t addCycles(uint64_t c){this->cycles += c; return this->cycles;}

    //Convert two 8bit numbers to 16bit number
    uint16_t getX16(uint8_t high, uint8_t low);

    //Check for even parity
    bool getEvenParity(uint8_t reg);

    //Log the current CPU state to the console
    void logState();

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
    uint16_t rIX;
    uint16_t rIY;
    uint16_t rSP;

    //Program Counter
    uint16_t rPC;

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

    //Boolean for expressing HALT state
    bool isHalt;
};
#endif