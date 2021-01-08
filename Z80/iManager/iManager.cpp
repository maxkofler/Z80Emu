#include "iManager.h"

IManager::IManager(Z80* z80, Log* log){
    this->z80 = z80;
    this->log = log;
    this->iSet = new ISet(this->z80);
}

uint8_t* IManager::fetchIS(uint16_t address){

    //Check if the curIS is set
    if (curIS != nullptr){
        delete[] curIS;
    }

    uint8_t opcode = this->z80->memoryManager->get(address);

    uint8_t operands = this->iSet->getOPBytes(opcode);

    this->curIS = new uint8_t[1+operands];

    for (int i = 0; i < operands; i++){
        curIS[i+1] = this->z80->memoryManager->get(address+1+i);
    }

    return curIS;

}