#include "z80.h"
#include "Z80/log/log.h"

int main(){
    Z80 z80(Log::D3);
    z80.mM->loadProgFromFile("prog.hex", 0x1000);
    z80.mM->setROM(0x2000, 0x2010);

    uint8_t* is = z80.iManager->fetchIS(0x1000); 
    z80.iManager->logIS(is);
    z80.iManager->execIS(is);   
    z80.logReg();
}