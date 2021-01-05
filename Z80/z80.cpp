#include "../z80.h"

Z80::Z80(int logLevel){
    this->log = new Log(logLevel);
    this->memoryManager = new MemoryManager(this->log);
}

uint16_t Z80::loadProgram(std::string path){
    return this->memoryManager->loadProgFromFile(path, 0x1000);
}
