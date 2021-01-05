#include "../z80.h"

Z80::Z80(int logLevel){
    this->log = new Log(logLevel);
    this->memoryManager = new MemoryManager(this->log);
}