#include "iomanager.h"

void IOManager::config(uint8_t addr, uint8_t mode){
    FUN();
    
    this->_config[addr] = mode;
}