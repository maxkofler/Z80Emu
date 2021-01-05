MemoryManager::MemoryManager(Log* log){
    this->memory = new uint8_t[__UINT16_MAX__];
    this->log = log;
}

uint16_t MemoryManager::loadProgFromFile(std::string path, uint16_t initpos){
    using namespace std;
    ifstream file;
    file.open(path, ios::in);
    
    if (file.is_open()){
        uint16_t pos = initpos;
        while (!file.eof() && file.good()){
            this->memory[pos] = file.get();
            log->log("MemoryManager::loadProgFromFile()", Log::toHexString(pos) + "->" + Log::toHexString(memory[pos]), Log::D);
            pos++;
        }
        return pos;
    }else{
        return 0;
    }
}

uint8_t MemoryManager::get(uint16_t pos){
    return this->memory[pos];
}

uint16_t MemoryManager::getX16(uint16_t pos){
    return (get(pos+1) << 8 ) | (get(pos) & 0xff);
}