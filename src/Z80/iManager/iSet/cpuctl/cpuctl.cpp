#include "cpuctl.h"

CPUctl::CPUctl(Z80* z80){
    FUN();
    this->z80 = z80;
}


uint16_t CPUctl::jp(bool c, uint16_t pos){
    FUN();

    if (c){
        LOGD("Jumping to " + Log::toHexString(pos));
        return pos;
    }else{
        return z80->PC();
    }
}


uint16_t CPUctl::jr(bool c, uint8_t off){
    FUN();

    if (c){
        char offset = off;
        uint16_t nPC = z80->PC() + offset;
        LOGD("Calculated offset: " + std::to_string(offset) + ", new PC (estimated)=" + Log::toHexString(nPC));
        return nPC; 
    }else{
        return z80->PC();
    }
}

uint16_t CPUctl::call(bool c, uint16_t pos){
    FUN();

    if (c){
        LOGD("Calling to " + Log::toHexString(pos));
        push(z80->PC());
        return pos;
    }else{
        return z80->PC();
    }
    
}
uint16_t CPUctl::ret(bool c){
    FUN();

    if (c){
        uint16_t pos = pop();
        LOGD("Returning from function to " + Log::toHexString(pos));
        return pos;
    }else{
        return z80->PC();
    }
}


void CPUctl::push(uint16_t v){
    FUN();
    //No flags affected
    uint8_t low = v & 0x00FF;
    uint8_t high = v >> 8;

    z80->SP(z80->SP()-1);
    z80->mM->set(z80->SP(), high);
    z80->SP(z80->SP()-1);
    z80->mM->set(z80->SP(), low);
}
uint16_t CPUctl::pop(){
    FUN();
    uint8_t low = z80->mM->get(z80->SP());
    z80->SP(z80->SP()+1);
    uint8_t high = z80->mM->get(z80->SP());
    z80->SP(z80->SP()+1);
    return z80->getX16(high, low);
}

void CPUctl::rst(uint8_t nv){
    FUN();

    push(z80->PC());
    z80->PC(nv);
    LOGW("This instruction is not verified! Use it with care!");
}

void CPUctl::ex(uint8_t* reg1a, uint8_t* reg2a, uint8_t* reg1b, uint8_t* reg2b){
    FUN();

    uint8_t a1 = *reg1a;
    uint8_t a2 = *reg2a;
    *reg1a = *reg1b;
    *reg2a = *reg2b;

    *reg1b = a1;
    *reg2b = a2;
}
void CPUctl::exx(){
    FUN();

    ex(z80->pB(), z80->pC(), z80->pBx(), z80->pCx());
    ex(z80->pD(), z80->pE(), z80->pDx(), z80->pEx());
    ex(z80->pH(), z80->pL(), z80->pHx(), z80->pLx());
}