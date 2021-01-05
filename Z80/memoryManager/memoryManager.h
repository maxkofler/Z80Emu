
/*
    -----MemoryManager-----

    -loadProgFromFile(string, uint16_t)
        ->1 path to program
        ->2 start position (default for Z80: 0x1000)
        !!  loads the program into the internal "memory" of the CPU
        <-  the ammount of bytes loaded (uint16_t)

    -get(uint16_t)
        ->  position to get from memory
        !!  /
        <-  the byte on that position (uint8_t)

    -getX16(uint16_t)
        ->  position to get from memory (first byte)
        !!  reads two bytes and connects them to a 16-bit uint
        <-  the 16-bit value (uint16_t) lsbfirst
*/




#ifndef __MEMORYMANAGER_H__
#define __MEMORYMANAGER_H__

#include "../log/log.h"

#include <string>
#include <fstream>
#include <stdint.h>

class MemoryManager{
public:
    MemoryManager(Log*);

    uint16_t loadProgFromFile(std::string, uint16_t);

    uint8_t get(uint16_t);
    uint16_t getX16(uint16_t);

private:
    Log* log;
    uint8_t* memory;
};

#include "memoryManager.cpp"
#endif