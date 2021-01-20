#include "bit.h"

Bit::Bit(Z80* z80){
    this->z80 = z80;
}

void Bit::bit(uint8_t pos, uint8_t reg){

}
void Bit::bit(uint8_t pos, uint16_t reg){
    
}

uint8_t Bit::res(uint8_t pos, uint8_t reg){
    return 0;
}
uint16_t Bit::res(uint8_t pos, uint16_t reg){
    return 0;
}

uint8_t Bit::set(uint8_t pos, uint8_t reg){
    return 0;
}
uint16_t Bit::set(uint8_t pos, uint16_t reg){
    return 0;
}