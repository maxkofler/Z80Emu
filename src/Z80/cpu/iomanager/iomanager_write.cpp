#include "iomanager.h"

bool IOManager::write(uint8_t addr, uint8_t data){
    FUN();

    LOGIO("PORT [" + Log::toHexString(addr) + "] < " + Log::toHexString(data));

    if (this->_config[addr] != IOManager::IN)
        this->_port[addr] = data;
    else{
        LOGE("IOError: writing to INPUT");
        return false;
    }
    return true;
}