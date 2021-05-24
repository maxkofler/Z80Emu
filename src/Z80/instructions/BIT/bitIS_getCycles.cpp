#include "bitIS.h"

uint8_t BitIS::getCycles(Instruction op){
    FUN();

    return this->_opCycles[op[0]];
}