#include "instructions/ixcb.h"

void IXCB::fetch(Z80EmuInstrucion& is){
    FUN();

    is.setCycles(this->_opCycles[is.getLastByte()]);

    LOGD("No operands needed in this set");
}