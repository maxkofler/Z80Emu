MemoryManager::MemoryManager(Log* log){
    this->memory = new uint8_t[__UINT16_MAX__];
    this->log = log;
    this->isROM = false;
}

void MemoryManager::setROM(uint16_t lowROM, uint16_t highROM){
    this->isROM = true;
    this->lROM = lowROM;
    this->hROM = highROM;
    log->log("MemoryManager::setROM()", "Marked " + Log::toHexString(lROM) + " - " + Log::toHexString(hROM) + " as ROM!", Log::D);
}

uint16_t MemoryManager::loadProgFromFile(std::string path, uint16_t initpos){
    using namespace std;
    log->log("MemoryManager::loadProgramFromFile()", "Reading program from file: " + path, Log::I);
    ifstream file;
    file.open(path, ios::in);
    
    if (file.is_open()){
        uint16_t pos = initpos;
        while (!file.eof() && file.good()){
            this->memory[pos] = file.get();
            log->log("MemoryManager::loadProgFromFile()", Log::toHexString(pos) + "->" + Log::toHexString(memory[pos]), Log::D3);
            pos++;
        }
        return pos;
    }else{
        log->log("MemoryManager::loadProgramFromFile()", "Failed to open file " + path, Log::E);
        return 0;
    }
}

uint8_t MemoryManager::get(uint16_t pos){
    return this->memory[pos];
}

uint16_t MemoryManager::getX16(uint16_t pos){
    return (get(pos+1) << 8 ) | (get(pos) & 0xff);
}

bool MemoryManager::set(uint16_t pos, uint8_t val){
    if (this->isROM){
        if (pos >= this->lROM && pos <= this->hROM){
            log->log("MemoryManager::set()", "Denied write to ROM at pos: " + Log::toHexString(pos) + " | " + Log::toHexString(val) + " -> [" + Log::toHexString(memory[pos]) + "]", Log::E);
            return false;
        }
    }
    log->log("MemoryManager::set()", "Writing(" + Log::toHexString(pos) + "): " + Log::toHexString(val) + " -> [" + Log::toHexString(memory[pos]) + "]", Log::D3);
    this->memory[pos] = val;
    return true;
}

bool MemoryManager::setX16(uint16_t pos, uint16_t val){
    uint8_t low = val & 0x00FF;
    uint8_t high = val >> 8;

    bool writeLow = true;

    if (this->isROM){
        bool ret = true;
        if (pos >= this->lROM && pos <= this->hROM){
            ret = false;
            log->log("MemoryManager::setX16()", "Denied write to ROM at pos: " + Log::toHexString(pos) + " | " + Log::toHexString(low) + " -> [" + Log::toHexString(memory[pos]) + "]", Log::E);
        }else{
            log->log("MemoryManager::set()", "Writing(" + Log::toHexString(pos) + "): " + Log::toHexString(low) + " -> [" + Log::toHexString(memory[pos]) + "]", Log::D3);
            this->memory[pos] = low;
        }

        if (pos+1 >= this->lROM && pos+1 <= this->hROM){
            ret = false;
            log->log("MemoryManager::setX16()", "Denied write to ROM at pos: " + Log::toHexString(pos+1) + " | " + Log::toHexString(low) + " -> [" + Log::toHexString(memory[pos+1]) + "]", Log::E);
        }else{
            log->log("MemoryManager::set()", "Writing(" + Log::toHexString(pos+1) + "): " + Log::toHexString(high) + " -> [" + Log::toHexString(memory[pos+1]) + "]", Log::D3);
            this->memory[pos+1] = high;
        }
        return ret;
    }

    log->log("MemoryManager::set()", "Writing(" + Log::toHexString(pos) + " - 16): " + Log::toHexString(val) + " -> [" + Log::toHexString(memory[pos]) + "]", Log::D3);
    this->memory[pos+1] = val >> 8;     // high byte
    this->memory[pos] = val & 0x00FF;   // low byte (0x34)
    return true;
}