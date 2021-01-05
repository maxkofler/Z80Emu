#include "z80.h"
#include "Z80/log/log.h"

int main(){
    Z80 z80(Log::D3);
    z80.memoryManager->loadProgFromFile("prog.hex", 0x1000);
    z80.memoryManager->setROM(0x2000, 0x2010);
}