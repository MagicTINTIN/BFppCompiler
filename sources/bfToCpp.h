#pragma once
#include <string>
#include <vector>
#include "bfppFunction.h"

class bfToCpp
{
private:
    std::string inputName;
    std::string content;
    std::vector<bfppFunction> functions;
public:
    bfToCpp(std::string fileName);
    ~bfToCpp();
    std::string toStr();
};