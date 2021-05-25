#include "iManager.h"

IManager::IManager(Z80* z80){
    FUN();
    this->z80 = z80;
    this->iSet = new ISet(this->z80);
}

IManager::~IManager(){
    FUN();

    delete this->iSet;
}

Instruction IManager::fetchIS(){
    FUN();
    if (this->ISLoaded){
        LOGW("finalizeIS() was not called! Please call to clean up pointers!");
    }

    //Read the opcode
    this->opcode = this->z80->readFromPCInc();

    Instruction curInstruction = this->iSet->fetchInstruction(this->opcode);

    return curInstruction;
}

void IManager::execIS(Instruction is){
    FUN();
    this->iSet->execIS(is);
    this->z80->addCycles(is.getCycles());
}

void IManager::logIS(Instruction is){
    FUN();
    uint8_t opcode = is[0];
    std::string instruction = "(" + Log::toHexString(opcode) + ")";
    for (size_t i = 1; i < is.size(); i++){
        instruction += ";" + Log::toHexString(is[i]);
    }
    LOGD("Current instruction: " + instruction);
}

void IManager::finalizeIS(Instruction is){
    FUN();
    this->ISLoaded = false;
}