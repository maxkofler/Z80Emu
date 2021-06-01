#include "iSet.h"

Z80EmuInstrucion ISet::fetchZ80EmuInstrucion(uint8_t opcode){
    FUN();

    Z80EmuInstrucion newZ80EmuInstrucion;
    newZ80EmuInstrucion.addByte(opcode);

    switch(opcode){
        case 0xcb:
            LOGI("Fetching using BIT instruction set");
            this->bitIS->fetch(newZ80EmuInstrucion);
            break;

        case 0xed:
            LOGI("Fetching using EXT instruction set");
            this->extIS->fetch(newZ80EmuInstrucion);
            break;

        default:
            LOGI("Fetching using MAIN instruction set");
            this->mainIS->fetch(newZ80EmuInstrucion);
            break;
    }

    return newZ80EmuInstrucion;
}