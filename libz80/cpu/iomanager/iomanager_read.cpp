#include "iomanager.h"

uint8_t IOManager::read(uint8_t addr){
    FUN();

    LOGIO("PORT [" + std::to_string(addr) + "] > " + Log::toHexString(this->_port[addr]));
    return this->_port[addr];
}