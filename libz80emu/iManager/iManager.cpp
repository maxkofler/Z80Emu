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

Z80EmuInstrucion IManager::fetchIS(){
    FUN();
    if (this->ISLoaded){
        LOGW("finalizeIS() was not called! Please call to clean up pointers!");
    }

    //Read the opcode
    this->opcode = this->z80->readFromPCInc();

    Z80EmuInstrucion curZ80EmuInstrucion = this->iSet->fetchZ80EmuInstrucion(this->opcode);

    return curZ80EmuInstrucion;
}

void IManager::execIS(Z80EmuInstrucion is){
    FUN();
    this->iSet->execIS(is);
    this->z80->addCycles(is.getCycles());
}

void IManager::logIS(Z80EmuInstrucion is){
    FUN();
    uint8_t opcode = is[0];
    std::string instruction = "(" + Log::toHexString(opcode) + ")";
    for (size_t i = 1; i < is.size(); i++){
        instruction += ";" + Log::toHexString(is[i]);
    }
    LOGD("Current instruction: " + instruction);
}

void IManager::finalizeIS(Z80EmuInstrucion is){
    FUN();
    this->ISLoaded = false;
}