#ifndef __LOG_H__
#define __LOG_H__

#include <string>
#include <iostream>
#include <iomanip>

enum LOG{
    V = 1,
    E = 2,
    W = 3,
    D = 4,
};

class Log{

public:
    Log(){}
    Log(int curLevel){
        setLevel(curLevel);
    }

    void setLevel(int level){
        lLevel = level+1;
    }

    const static int E = 1;
    const static int V = 2;
    const static int W = 3;
    const static int I = 4;
    const static int I2 = 5;
    const static int D = 6;
    const static int D2 = 7;
    const static int D3 = 8;


    //Default logging
    void log(std::string tag, std::string msg, int loglevel){
        if (loglevel < lLevel){
            std::cout << "[" << loglevel << "]" << tag << " - " << msg << std::endl;
        }
        
    }
    void log(std::string tag, std::string msg){
        std::cout << "[---]" << tag << " - " << msg << std::endl; 
    }
    void log(std::string msg){
        std::cout << "[---]" << msg << std::endl;
    }
    

    //Logging for program errors, like warnings for programmers
    void logprg(std::string function, std::string msg, int loglevel){
        if (loglevel < lLevel){
            std::cout << "(" << loglevel << ")" << "{prg-log}" << "[" << function << "]" << msg << std::endl;
        }
    }

    const static std::string toHexString(uint16_t num){
        std::stringstream sstream;
        sstream << "0x" << std::hex << num;
        return sstream.str();
    }



private:
    int lLevel;
};

#endif