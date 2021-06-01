#include "instructions/iycb.h"

void IYCB::fetch(Z80EmuInstrucion& is){
    FUN();

    is.setCycles(this->_opCycles[is.getLastByte()]);

    LOGD("No operands needed in this set");
}