#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "bfToCpp.h"

std::string genBaseFile()
{
    std::string rtn = "";
    return rtn;
}

/* BF TO CPP CONVERTER */

bfToCpp::bfToCpp(std::string fileName) : inputName(fileName)
{
    bfppFunction mainFunction("main");
    functions.emplace_back(mainFunction);

    std::fstream fromBf(fileName, std::fstream::in);
    char ch;
    while (fromBf >> std::noskipws >> ch)
    {
        std::cout << ch;
    }
}

bfToCpp::~bfToCpp()
{
}

/* FUNCTION GENERATOR */

bfppFunction::bfppFunction(std::string functionName): name(functionName)
{

}

bfppFunction::~bfppFunction()
{
}