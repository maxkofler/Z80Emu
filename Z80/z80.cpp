#include "../z80.h"

Z80::Z80(int logLevel){
    this->log = new Log(logLevel);
    this->mM = new MemoryManager(this->log);
    this->iManager = new IManager(this, this->log);
}


uint16_t Z80::getX16(uint8_t h, uint8_t l){
    return (h << 8) | (l & 0xff);
}

void Z80::BC(uint16_t v){
    this->rB = v & 0x00FF;  //LOW
    this->rC = v >> 8;      //HIGH
}

void Z80::DE(uint16_t v){
    this->rD = v & 0x00FF;  //LOW
    this->rE = v >> 8;      //HIGH
}

void Z80::HL(uint16_t v){
    this->rH = v & 0x00FF;  //LOW
    this->rL = v >> 8;      //HIGH
}

void Z80::logState(){
    using namespace std;
    cout << endl;
    cout << "A=" << Log::toHexString(rA) << "=" << Log::toBinString(rA) << "\t";
    cout << "S=" << Sf << " Z=" << Zf << " H=" << Hf << " PV=" << PVf << " N=" << Nf << " C=" << Cf << endl;
    cout << "B=" << Log::toHexString(rB) << "=" << Log::toBinString(rB) << "\t C=" << Log::toHexString(rC) << "=" << Log::toBinString(rC) << endl;
    cout << "D=" << Log::toHexString(rD) << "=" << Log::toBinString(rD) << "\t E=" << Log::toHexString(rE) << "=" << Log::toBinString(rE) << endl;
    cout << "H=" << Log::toHexString(rH) << "=" << Log::toBinString(rH) << "\t L=" << Log::toHexString(rL) << "=" << Log::toBinString(rL) << endl;
    cout << endl;
}