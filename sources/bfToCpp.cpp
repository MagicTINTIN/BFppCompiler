#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "bfppFunction.h"
#include "bfToCpp.h"

std::string genBaseFile()
{
    std::string rtn = "// File generated using Brainfuck++ Compiler\n";
    rtn += "#include <string>\n";
    rtn += "#include <vector>\n";
    rtn += "#include <iostream>\n";
    rtn += "#include <fstream>\n";
    rtn += "#include <stdio.h>\n\n";

    rtn += "bool moveLeft(int &position)\n{\n";
    rtn += TAB + "if (position > 0) {position--; return false;}\n";
    rtn += TAB + "return true;\n";
    rtn += "}\n";
    rtn += "void moveRight(std::vector<uchar> &mem, int &position)\n{\n";
    rtn += TAB + "position--;\n";
    rtn += TAB + "if (position == mem.size) mem.emplace_back(0);\n";
    rtn += "}\n";
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

std::string bfToCpp::toStr()
{
    std::string rtn = genBaseFile();
    for (size_t i = 0; i < functions.size(); i++)
    {
        bfppFunction fct = functions[i];
        if (fct.validFinalHeight())
        {
            rtn += fct.toStr();
        }
        else
        {
            std::cerr << "Compilation failed: the number of '[' doesn't march the number of ']'!\n";
            return "-1";
        }
    }
    return rtn;
}