#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "getArguments.h"
#include "bfToCpp.h"

const std::string version("b0.1");

int main(int argc, char const *argv[])
{
    bool keepIntermediate(false);
    std::string inputFile(""), intermediateFile(""), outputFile("");

    std::vector<std::string> args(argv, argv + argc);
    int argRes = getArguments(version, args, inputFile, intermediateFile, outputFile, keepIntermediate);
    if (argRes != 0) {
        if (argRes > 0)
            return 0;
        else
            return -argRes;
    }
    if (inputFile == "") {
        std::cout << "Missing brainfuck file input (source code).\nType bfpp --help to get more help.\n";
        return 2;
    }

    std::ofstream toCpp(intermediateFile);

    std::cout << "Converting brainfuck to cpp...\n";
    bfToCpp code(inputFile);
    std::string codeStr = code.toStr();
    std::cout << codeStr;
    toCpp << codeStr;

    return 0;
}
