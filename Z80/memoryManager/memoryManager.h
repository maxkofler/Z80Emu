#ifndef __MEMORYMANAGER_H__
#define __MEMORYMANAGER_H__

#include <string>
#include <fstream>
#include <stdint.h>

class MemoryManager{
public:
    MemoryManager();

    uint16_t loadProgFromFile(std::string);

private:
    uint8_t* memory;
};

#include "memoryManager.cpp"
#endif