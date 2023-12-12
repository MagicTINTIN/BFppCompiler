#pragma once
#include <string>

class bfppFunction
{
private:
    std::string name;
    std::string content;
public:
    bfppFunction(std::string functionName);
    ~bfppFunction();
    std::string toStr();
};