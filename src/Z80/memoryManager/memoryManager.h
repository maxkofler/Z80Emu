
/*
    -----MemoryManager-----

    -setROM(uint16_t, uint16_t)
        ->1 first position of ROM
        ->2 last position of ROM
        !!  Marks the area as ROM (inclusive provided positions)
        <-  /

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
        <-  the 16-bit value (uint16_t) lsBfirst

    -set(uint16_t, uint8_t)
        ->1 position to write to
        ->2 value to write
        !!  changes the memory location to a value
        <-  true if value was written, false if position is marked as ROM

    -setX16(uint16_t, uint16_t)
        ->1 postition to write (first byte)
        ->2 value to write
        !!  changes the memory location to the provided value (lsBfirst)
        <-  true if value was written, false if position is marked as ROM
*/




#ifndef __MEMORYMANAGER_H__
#define __MEMORYMANAGER_H__

#include "../log/log.h"

#include <string>
#include <fstream>
#include <stdint.h>

class MemoryManager{
public:
    MemoryManager();

    void setROM(uint16_t, uint16_t);

    uint16_t loadProgFromFile(std::string, uint16_t);

    uint8_t get(uint16_t);
    uint16_t getX16(uint16_t);

    bool set(uint16_t, uint8_t);
    bool setX16(uint16_t, uint16_t);

private:
    uint8_t* memory;

    bool isROM;
    uint16_t lROM;
    uint16_t hROM;
};

#endif