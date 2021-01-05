#include "z80.h"
#include "Z80/log/log.h"

int main(){
    Z80 z80(6);
    z80.loadProgram("prog.hex");
    Log log(5);
    log.log("Mem 0x1000 (8) = " + Log::toHexString(z80.getMemory(0x1000)));
    log.log("Mem 0x1000 (16) = " + Log::toHexString(z80.getMemoryX16(0x1000)));

}