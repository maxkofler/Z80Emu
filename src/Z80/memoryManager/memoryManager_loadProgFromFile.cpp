#include "memoryManager.h"

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