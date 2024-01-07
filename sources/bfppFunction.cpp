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

std::string bfppFunction::getName() { return name; }

std::string bfppFunction::toStr()
{
    std::string rtn = "";
    if (name == "main")
    {
        rtn += "int main()\n{\n";
        rtn += TAB + "std::vector<unsigned char> memory;\n";
        rtn += TAB + "memory.emplace_back(0);\n";
        rtn += TAB + "int cursor(0);\n";
        rtn += TAB + "std::string temp;\n";
    }
    else
    {
        rtn += "void " + name + "(std::vector<unsigned char> &memory, int &cursor)\n{\n";
    }

    rtn += content;
    rtn += "}\n\n";
    return rtn;
}

void bfppFunction::addOB()
{
    content += tabGen(height) + "while (memory[cursor] > 0) {\n";
    height++;
}

bool bfppFunction::addCB()
{
    if (height > 1)
    {
        height--;
        content += tabGen(height) + "}\n";
        return false;
    }
    return true;
}

void bfppFunction::addPlus()
{
    content += tabGen(height) + "memory[cursor]++;\n";
}

void bfppFunction::addMinus()
{
    content += tabGen(height) + "memory[cursor]--;\n";
}

void bfppFunction::addLeft()
{
    content += tabGen(height) + "if (moveLeft(cursor)) {\n";
    content += tabGen(height+1) + "std::cerr << RIGHT_ERROR_MSG;\n";
    content += tabGen(height+1) + "return 1;\n";
    content += tabGen(height) + "}\n";
}

void bfppFunction::addRight()
{
    content += tabGen(height) + "moveRight(memory, cursor);\n";
}

void bfppFunction::addCin()
{
    content += tabGen(height) + "std::cout << ENTER_CHAR;\n";
    content += tabGen(height) + "getline(std::cin, temp);\n";
    content += tabGen(height) + "if (!temp.empty()) memory[cursor] = temp[0];\n";
}

void bfppFunction::addCout()
{
    content += tabGen(height) + "std::cout << memory[cursor];\n";
}

void bfppFunction::addPause()
{
    content += tabGen(height) + "std::cout << PAUSE_MSG;\n";
    content += tabGen(height) + "std::cin.get();\n";
}

void bfppFunction::addDebug()
{
    content += tabGen(height) + "debugMemory(memory,cursor);\n";
}

void bfppFunction::addExit()
{
    content += tabGen(height) + "return 0;\n";
}

bool bfppFunction::validFinalHeight()
{
    return height == 1;
}