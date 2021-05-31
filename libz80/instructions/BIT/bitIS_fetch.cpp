#include "instructions/bitIS.h"

void BitIS::fetch(Instruction& is){
    FUN();

    is.setCycles(this->_opCycles[is[0]]);
    //There are no operands to fetch
}