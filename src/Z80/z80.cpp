#include "../z80.h"

Z80::Z80(int logLevel){
    this->log = new Log(logLevel);
    this->mM = new MemoryManager(this->log);
    this->iManager = new IManager(this, this->log);

    this->cycles = 0;
}


uint16_t Z80::getX16(uint8_t h, uint8_t l){
    return (h << 8) | (l & 0xff);
}

bool Z80::getEvenParity(uint8_t reg){
    uint8_t count = 0;
    for(int i = 0; i < 32; i++){
        if(reg & (1 << i)){ count++; }
    }
    return count%2;
}

void Z80::BC(uint16_t v){
    this->rC = v & 0x00FF;  //LOW
    this->rB = v >> 8;      //HIGH
}

void Z80::DE(uint16_t v){
    this->rE = v & 0x00FF;  //LOW
    this->rD = v >> 8;      //HIGH
}

void Z80::HL(uint16_t v){
    this->rL = v & 0x00FF;  //LOW
    this->rH = v >> 8;      //HIGH
}

void Z80::logState(){
    using namespace std;
    cout << endl;
    cout << "A=" << Log::toHexString(rA) << " = " << Log::toBinString(rA) << "\t";
    cout << "S=" << Sf << " Z=" << Zf << " H=" << Hf << " PV=" << PVf << " N=" << Nf << " C=" << Cf << endl;
    cout << "B=" << Log::toHexString(rB) << " = " << Log::toBinString(rB) << "\t C=" << Log::toHexString(rC) << " = " << Log::toBinString(rC) << endl;
    cout << "D=" << Log::toHexString(rD) << " = " << Log::toBinString(rD) << "\t E=" << Log::toHexString(rE) << " = " << Log::toBinString(rE) << endl;
    cout << "H=" << Log::toHexString(rH) << " = " << Log::toBinString(rH) << "\t L=" << Log::toHexString(rL) << " = " << Log::toBinString(rL) << endl;

    cout << "PC=" << Log::toHexString(rPC) << "\tSP=" << Log::toHexString(rSP) << "\tCycles=" << cycles <<endl;
    cout << endl;
}