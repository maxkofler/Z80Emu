#include "cpuctl.h"

CPUctl::CPUctl(Z80* z80, Log* log){
    this->z80 = z80;
    this->log = log;
}

//If condition is true, ** wil be returned and so copied into PC
uint16_t    CPUctl::jp      (bool c, uint16_t pos){
    if (c){
        return pos;
    }
}

//If condition is true, *(offset - signed) will be added to PC
//and then copied to PC
uint16_t    CPUctl::jr      (bool c, uint8_t off){
    if (c){
        char offset = off;
        uint16_t nPC = z80->PC() + offset;
        log->log("CPUctl-jr()", "Calculated offset: " + std::to_string(offset) + ", new PC (estimated):" + std::to_string(nPC), Log::D3);
    }
}

uint16_t    CPUctl::call    (bool c, uint16_t pos){
    return 0;
}
uint16_t    CPUctl::ret     (bool c){
    return 0;
}

void        CPUctl::push    (uint16_t v){

}
uint16_t    CPUctl::pop     (){
    return 0;
}

void        CPUctl::rst     (uint8_t nv){

}

void        CPUctl::ex      (uint8_t* reg1a, uint8_t* reg2a, uint8_t* reg1b, uint8_t* reg2b){
    uint8_t a1 = *reg1a;
    uint8_t a2 = *reg2a;
    *reg1a = *reg1b;
    *reg2a = *reg2b;

    *reg1b = a1;
    *reg2b = a2;
}
void        CPUctl::exx     (){

}