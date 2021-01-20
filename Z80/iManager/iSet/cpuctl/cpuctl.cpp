#include "cpuctl.h"

CPUctl::CPUctl(Z80* z80){
    this->z80 = z80;
}

uint16_t    CPUctl::jp      (bool c, uint16_t pos){
    return 0;
}
uint16_t    CPUctl::jr      (bool c, uint8_t off){
    return 0;
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

void        CPUctl::rst     (uint16_t nv){

}

void        CPUctl::ex      (uint16_t* reg1, uint16_t* reg2){

}
void        CPUctl::exx     (){

}