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

    z80.PC(0x1000);

    while (run){
        cout << ">";
        cin >> command;

        if (command == "is"){

            if (!z80.HALT()){
                is = z80.iManager->fetchIS(); 
                z80.iManager->logIS(is);
                z80.iManager->execIS(is);   
                z80.logReg();
                z80.iManager->finalizeIS(is);
            }else{
                cout << "Processor is in halt state! Type PC to enter new start address!" << endl;
            }
            

        }else if (command == "PC"){
            cout << "PC(hex)=";
            cin >> command;
            z80.PC(stoul(command, nullptr, 16));
            z80.HALT(false);
            cout << "new PC = " << Log::toHexString(z80.PC()) << endl;
        }
        
        
        
        else if (command == "quit"){
            run = false;
        }else{
            cout << "Command not found!" << endl;
        }
    }
    
}