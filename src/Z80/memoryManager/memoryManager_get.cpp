#include "memoryManager.h"

uint8_t MemoryManager::get(uint16_t pos){
    FUN();
    LOGMEM("MEM [" + Log::toHexString(pos) + "] > " + Log::toHexString(this->memory[pos]));
    return this->memory[pos];
}

uint16_t MemoryManager::getX16(uint16_t pos){
    FUN();
    return (get(pos+1) << 8 ) | (get(pos) & 0xff);
}