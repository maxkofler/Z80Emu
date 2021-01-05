#ifndef __IMANAGER_H__
#define __IMANAGER_H__

#include <string>
#include <stdint.h>

class IManager{

public:
    IManager(std::string);

private:
    std::string progPath;
};

#include "iManager.cpp"
#endif