#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "bfppFunction.h"

std::string tabGen(int numberOfTabs)
{
    std::string rtn = "";
    for (size_t i = 0; i < numberOfTabs; i++)
    {
        rtn += TAB;
    }
    return rtn;
}

/* FUNCTION GENERATOR */

bfppFunction::bfppFunction(std::string functionName) : name(functionName)
{
}

bfppFunction::~bfppFunction()
{
}

std::string bfppFunction::toStr()
{
    std::string rtn = "";
    if (name == "main")
    {
        rtn += name + "int main()\n{\n";
        rtn += TAB + "std::vector<uchar> memory;\n";
        rtn += TAB + "memory.emplace_back(0);\n";
        rtn += TAB + "int cursor(0);\n";
    }
    else
    {
        rtn += "void " + name + "()\n{\n";
    }

    rtn += content;
    rtn += "}\n\n";
    return rtn;
}

void bfppFunction::addOB()
{
    content += "while (memory[cursor] > 0)\n{\n";
    height++;
}

bool bfppFunction::addCB()
{
    if (height > 1)
    {
        content += "}\n";
        height--;
        return false;
    }
    return true;
}

void bfppFunction::addPlus()
{
    content += "\n";
}

void bfppFunction::addMinus()
{
    content += "\n";
}

void bfppFunction::addLeft()
{
    content += "\n";
}

void bfppFunction::addRight()
{
    content += "\n";
}

void bfppFunction::addCin()
{
    content += "\n";
}

void bfppFunction::addCout()
{
    content += "\n";
}


bool bfppFunction::validFinalHeight()
{
    return height == 1;
}