#include "z80emu.h"

void Z80::BC(uint16_t v){
    FUN();

    this->rC = v & 0x00FF;  //LOW
    this->rB = v >> 8;      //HIGH
}

void Z80::DE(uint16_t v){
    FUN();

    this->rE = v & 0x00FF;  //LOW
    this->rD = v >> 8;      //HIGH
}

void Z80::HL(uint16_t v){
    this->rL = v & 0x00FF;  //LOW
    this->rH = v >> 8;      //HIGH
}