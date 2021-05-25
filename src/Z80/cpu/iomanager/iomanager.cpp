#include "iomanager.h"

IOManager::IOManager(Z80* z80){
    FUN();

    this->z80 = z80;
    
    this->_config = new uint8_t[256] {255};
    this->_port = new uint8_t[256] {0};
}

IOManager::~IOManager(){
    FUN();

    delete[] this->_config;
    delete[] this->_port;
}