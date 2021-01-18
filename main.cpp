#include "z80.h"
#include "Z80/log/log.h"

#include <iostream>
#include <string>

int main(){
    using namespace std;
    
    Z80 z80(Log::D3);
    z80.mM->loadProgFromFile("prog.hex", 0x1000);
    z80.mM->setROM(0x2000, 0x2010);

    bool run = true;
    string command;

    uint8_t* is;

    uint16_t PC = 0x1000;

    while (run){
        cout << ">";
        cin >> command;

        if (command == "is"){

            is = z80.iManager->fetchIS(PC); 
            z80.iManager->logIS(is);
            z80.iManager->execIS(is);   
            z80.logReg();
            PC++;

        }else if (command == "PC"){
            cout << "PC=";
            cin >> command;
            PC = stoul(command, nullptr, 16);
            cout << "new PC = " << Log::toHexString(PC) << endl;
        }
        
        
        
        else if (command == "quit"){
            run = false;
        }else{
            cout << "Command not found!" << endl;
        }
    }
    
}