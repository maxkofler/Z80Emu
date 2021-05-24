#include "iManager.h"

IManager::IManager(Z80* z80){
    FUN();
    this->z80 = z80;
    this->iSet = new ISet(this->z80);
}

uint8_t* IManager::fetchIS(){
    FUN();
    if (this->ISLoaded){
        LOGW("finalizeIS() was not called! Please call to clean up pointers!");
    }

    this->opcode = this->z80->mM->get(z80->PC());
    z80->PC(z80->PC()+1);

    uint8_t operands = this->iSet->getOPBytes(opcode);
    LOGD("Fetching " + std::to_string(operands) + " operands!");

    uint8_t* curIS = new uint8_t[operands+1];
    this->ISLoaded = true;
    curIS[0] = opcode;

    for (int i = 0; i < operands; i++){
        curIS[i+1] = this->z80->mM->get(z80->PC());
        z80->PC(z80->PC()+1);
    }

    return curIS;
}

void IManager::execIS(uint8_t* is){
    FUN();
    this->iSet->execIS(is);
    this->z80->addCycles(this->iSet->getISCycles(is[0]));
}

void IManager::logIS(uint8_t* is){
    FUN();
    uint8_t opcode = is[0];
    std::string instruction = "(" + Log::toHexString(opcode) + ")";
    for (int i = 1; i < this->iSet->getOPBytes(opcode); i++){
        instruction += ";" + Log::toHexString(is[i]);
    }
    LOGD("Current instruction: " + instruction);
}

void IManager::finalizeIS(uint8_t* is){
    FUN();
    delete[] is;
    this->ISLoaded = false;
}