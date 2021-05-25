#include "iomanager.h"

void IOManager::config(uint8_t addr, uint8_t mode){
    FUN();
    
    LOGD("Configuring " + Log::toHexString(addr) + " with mode " + Log::toHexString(mode));
    this->_config[addr] = mode;
}