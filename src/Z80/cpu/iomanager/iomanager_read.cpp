#include "iomanager.h"

uint8_t IOManager::read(uint8_t addr){
    FUN();

    return this->_port[addr];
}