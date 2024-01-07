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
    bool fileNotFound = false;
    std::string errorString="";
public:
    bfToCpp(std::string fileName);
    ~bfToCpp();
    std::string toStr();
};