#include "memoryManager.h"
MemoryManager::MemoryManager(){
    this->memory = new uint8_t[__UINT16_MAX__];
    this->isROM = false;
}

void MemoryManager::setROM(uint16_t lowROM, uint16_t highROM){
    FUN();
    this->isROM = true;
    this->lROM = lowROM;
    this->hROM = highROM;
    LOGI("Marked " + Log::toHexString(lROM) + " - " + Log::toHexString(hROM) + " as ROM!");
}

uint16_t MemoryManager::loadProgFromFile(std::string path, uint16_t initpos){
    FUN();
    using namespace std;
    LOGI("Reading program from file: " + path);
    ifstream file;
    file.open(path, ios::in);
    
    if (file.is_open()){
        uint16_t pos = initpos;
        while (!file.eof() && file.good()){
            this->memory[pos] = file.get();
            LOGD(Log::toHexString(pos) + "->" + Log::toHexString(memory[pos]));
            pos++;
        }
        return pos;
    }else{
        LOGE("Failed to open file " + path);
        return 0;
    }
}

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

bool MemoryManager::setX16(uint16_t pos, uint16_t val){
    FUN();
    uint8_t low = val & 0x00FF;
    uint8_t high = val >> 8;

    bool writeLow = true;

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