#include "memoryManager.h"

#ifndef __UINT16_MAX__
#define __UINT16_MAX__ UINT16_MAX
#endif

MemoryManager::MemoryManager(){
    FUN();
    this->memory = new uint8_t[__UINT16_MAX__];
    this->isROM = false;
}

MemoryManager::~MemoryManager(){
    FUN();
    delete[] this->memory;
}