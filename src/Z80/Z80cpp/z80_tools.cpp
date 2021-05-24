#include "../z80.h"

uint16_t Z80::getX16(uint8_t h, uint8_t l){
    FUN();

    return (h << 8) | (l & 0xff);
}

bool Z80::getEvenParity(uint8_t reg){
    FUN();
    
    uint8_t count = 0;
    for(int i = 0; i < 32; i++){
        if(reg & (1 << i)){ count++; }
    }
    return count%2;
}

void Z80::logState(){
    using namespace std;
    cout << endl;
    cout << "A=" << Log::toHexString(rA) << " = " << Log::toBinString8(rA) << "\t";
    cout << "S=" << Sf << " Z=" << Zf << " H=" << Hf << " PV=" << PVf << " N=" << Nf << " C=" << Cf << endl;
    cout << "B=" << Log::toHexString(rB) << " = " << Log::toBinString8(rB) << "\t C=" << Log::toHexString(rC) << " = " << Log::toBinString8(rC) << endl;
    cout << "D=" << Log::toHexString(rD) << " = " << Log::toBinString8(rD) << "\t E=" << Log::toHexString(rE) << " = " << Log::toBinString8(rE) << endl;
    cout << "H=" << Log::toHexString(rH) << " = " << Log::toBinString8(rH) << "\t L=" << Log::toHexString(rL) << " = " << Log::toBinString8(rL) << endl;

    cout << "PC=" << Log::toHexString(rPC) << "\tSP=" << Log::toHexString(rSP) << "\tCycles=" << cycles <<endl;
    cout << endl;
}