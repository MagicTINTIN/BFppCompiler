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
        rtn += functions[i].toStr();
    }
    return rtn;
}