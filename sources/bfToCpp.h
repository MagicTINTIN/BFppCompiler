#pragma once
#include <string>

class bfToCpp
{
private:
    std::string inputName;
    std::string content;
    std::vector<bfppFunction> functions;
public:
    bfToCpp(std::string fileName);
    ~bfToCpp();
};

class bfppFunction
{
private:
    std::string name;
    std::string content;
public:
    bfppFunction(std::string functionName);
    ~bfppFunction();
};