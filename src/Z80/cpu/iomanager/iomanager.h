#ifndef __IOMANAGER_H__
#define __IOMANAGER_H__

class IOManager;

#include "../../log/log.h"

class IOManager{
public:
    IOManager();
    ~IOManager();

    //Possible IO configurations
    //Read only from CPU
    const static uint8_t IN = 0;
    //Writeable from CPU
    const static uint8_t OUT = 1;
    //Not configured [random results, no affection on write]
    const static uint8_t NONE = 255;

    /**
     *  Configure the port
     *  @arg    addr            The address to configure
     *  @arg    mode            The mode to set the port
     **/
    void                        config(uint8_t addr, uint8_t mode);

    /**
     *  Write to a port
     *  @arg    addr            The address to write to
     *  @arg    data            The byte to write to this address
     *  @return                 False on error (eg. not an output)
     **/
    bool                        write(uint8_t addr, uint8_t data);

    /**
     *  Read from a port, does not have any errors, the CPU can read anywhere
     *  @arg    addr            The address to read from
     *  @return                 The byte read from the port
     **/    
    uint8_t                     read(uint8_t addr);

private:

    //Stores the config of the ports:
    //  0   IN
    //  1   OUT
    //  ...
    //  255 NONE
    uint8_t*                    _config;
    uint8_t*                    _port;
};

#endif