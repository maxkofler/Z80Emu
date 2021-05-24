#include "mainIs.h"

void MainIS::fetch(Instruction& instruction){
    FUN();

    switch (instruction.getLastByte())
    {
    case 0xcb:
        //Switch to BIT instructions
        LOGI("Using bit instructions");
        break;
    
    case 0xdd:
        //Switch to IX instructions
        LOGI("Using IX instructions");

        break;

    case 0xed:
        //Switch to EXTD instructions
        LOGI("Using EXTD instructions");
        break;

    case 0xfd:
        //Switch to IY instructions
        LOGI("Using IY instructions");
        break;

    default:
        //Use MAIN instructions
        LOGI("Using MAIN instructions");
        for (uint8_t i = 0; i < this->_opBytes[instruction[0]]; i++){
            instruction.addByte(z->readFromPCInc());
        }
        break;
    }
}