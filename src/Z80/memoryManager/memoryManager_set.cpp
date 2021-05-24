#include "memoryManager.h"

bool MemoryManager::setX16(uint16_t pos, uint16_t val){
    FUN();
    uint8_t low = val & 0x00FF;
    uint8_t high = val >> 8;

    if (this->isROM){
        bool ret = true;
        if (pos >= this->lROM && pos <= this->hROM){
            ret = false;
            LOGW(   "Denied write to ROM at pos: " + Log::toHexString(pos) + " | " + 
                    Log::toHexString(low) + " -> [" + Log::toHexString(memory[pos]) + "]");
        }else{
            LOGMEM( "Writing(" + Log::toHexString(pos) + "): " + Log::toHexString(low) + " -> [" + 
                    Log::toHexString(memory[pos]) + "]");
            this->memory[pos] = low;
        }

        if (pos+1 >= this->lROM && pos+1 <= this->hROM){
            ret = false;
            LOGW(   "Denied write to ROM at pos: " + Log::toHexString(pos+1) + " | " + 
                    Log::toHexString(low) + " -> [" + Log::toHexString(memory[pos+1]) + "]");
        }else{
            LOGMEM( "Writing(" + Log::toHexString(pos+1) + "): " + Log::toHexString(high) + " -> [" +
                    Log::toHexString(memory[pos+1]) + "]");
            this->memory[pos+1] = high;
        }
        return ret;
    }

    LOGMEM( "Writing(" + Log::toHexString(pos) + " - 16): " + Log::toHexString(val) + " -> [" + 
            Log::toHexString(memory[pos]) + "]");
    this->memory[pos+1] = val >> 8;     // high byte
    this->memory[pos] = val & 0x00FF;   // low byte (0x34)
    return true;
}

bool MemoryManager::set(uint16_t pos, uint8_t val){
    FUN();
    if (this->isROM){
        if (pos >= this->lROM && pos <= this->hROM){
            LOGW(   "Denied write to ROM at pos: " + Log::toHexString(pos) + " | " + 
                    Log::toHexString(val) + " -> [" + Log::toHexString(memory[pos]) + "]");
            return false;
        }
    }
    LOGMEM( "Writing(" + Log::toHexString(pos) + "): " + Log::toHexString(val) + " -> [" + 
            Log::toHexString(memory[pos]) + "]");
    this->memory[pos] = val;
    return true;
}