#include "memoryManager.h"

uint8_t MemoryManager::get(uint16_t pos){
    FUN();
    LOGMEM("Read " + Log::toHexString(pos) + " -> [" + Log::toHexString(this->memory[pos]) + "]");
    return this->memory[pos];
}

uint16_t MemoryManager::getX16(uint16_t pos){
    FUN();
    LOGMEM( "Read (16) " + Log::toHexString(pos) + " -> [" + 
            Log::toHexString(this->memory[pos]) + "-" + Log::toHexString(this->memory[pos+1]) + "]");
    return (get(pos+1) << 8 ) | (get(pos) & 0xff);
}