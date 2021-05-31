#include "memoryManager.h"

void MemoryManager::setROM(uint16_t lowROM, uint16_t highROM){
    FUN();
    this->isROM = true;
    this->lROM = lowROM;
    this->hROM = highROM;
    LOGI("Marked " + Log::toHexString(lROM) + " - " + Log::toHexString(hROM) + " as ROM!");
}