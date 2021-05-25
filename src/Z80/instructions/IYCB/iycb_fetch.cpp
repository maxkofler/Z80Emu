#include "iycb.h"

void IYCB::fetch(Instruction& is){
    FUN();

    is.setCycles(this->_opCycles[is.getLastByte()]);

    LOGD("No operands needed in this set");
}