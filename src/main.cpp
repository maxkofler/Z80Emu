#include "Z80/z80.h"
#include "Z80/log/log.h"

#include <iostream>
#include <string>

Log* hlog;

int main(int argc, char** argv){
    hlog = new Log(Log::IO, false);
    using namespace std;
    
    Z80 z80;

    if (argc == 2){
        cout << "Loading program from \"" << argv[1] << "\"" << endl;
        z80.mM->loadProgFromFile(argv[1], 0x1000);
    }else{
        cout << "Loading program from default \"prog.hex\"" << endl;
        if (z80.mM->loadProgFromFile("prog.hex", 0x1000) == 0){
            cout << "Error in loading program!" << endl;
            return 0;
        }
    }
    
    z80.mM->setROM(0x2000, 0x2010);

    bool run = true;
    string command;

    Instruction is;

    z80.PC(0x1000);
    z80.logState();

    while (run){
        cout << ">";
        cin >> command;

        if (command == "is" || command == "i"){

            if (!z80.HALT()){
                is = z80.iManager->fetchIS(); 
                z80.iManager->logIS(is);
                z80.iManager->execIS(is);   
                z80.logState();
                z80.iManager->finalizeIS(is);
            }else{
                cout << "Processor is in halt state! Type PC to enter new start address" << endl;
            }
            

        }else if (command == "pc"){
            cout << "PC(hex)= ";
            cin >> command;
            z80.PC(stoul(command, nullptr, 16));
            z80.HALT(false);
            cout << "new PC = " << Log::toHexString(z80.PC()) << endl;
        }
        
        else if (command == "ioconf"){
            cout << "port(hex)= ";
            cin >> command;
            uint8_t port = stoul(command, nullptr, 16);
            cout << "mode(hex 0=IN, 1=OUT)= ";
            cin >> command;
            uint8_t mode = stoul(command, nullptr, 16);
            z80.ioManager->config(port, mode);
        }

        else if (command == "iopoke"){
            cout << "port(hex)= ";
            cin >> command;
            uint8_t port = stoul(command, nullptr, 16);
            cout << "data(hex)= ";
            cin >> command;
            uint8_t data = stoul(command, nullptr, 16);
            z80.ioManager->userWrite(port, data);
        }

        else if (command == "iopeek"){
            cout << "port(hex)= ";
            cin >> command;
            uint8_t port = stoul(command, nullptr, 16);
            z80.ioManager->read(port);
        }
        
        else if (command == "exit" || command == "q"){
            run = false;
        }
        
        else if (command == "halt"){
            z80.HALT(true);
            cout << "Set processor to HALT state" << endl;
        }

        else if (command == "state"){
            z80.logState();
        }
        
        else{
            cout << "Command not found" << endl;
        }
    }
    
}