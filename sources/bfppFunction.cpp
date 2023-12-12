#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "bfppFunction.h"

/* FUNCTION GENERATOR */

bfppFunction::bfppFunction(std::string functionName) : name(functionName)
{
}

bfppFunction::~bfppFunction()
{
}

std::string bfppFunction::toStr()
{
    std::string rtn = name == "main" ? "int " : "void ";
    rtn += name + "()\n{\n";
    rtn += "}\n\n";
    return rtn;
}