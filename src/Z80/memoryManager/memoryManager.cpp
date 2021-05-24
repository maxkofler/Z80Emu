#include "memoryManager.h"
MemoryManager::MemoryManager(){
    FUN();
    this->memory = new uint8_t[__UINT16_MAX__];
    this->isROM = false;
}

MemoryManager::~MemoryManager(){
    FUN();
    delete[] this->memory;
}