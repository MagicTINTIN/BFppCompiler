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
    if (argRes != 0)
    {
        if (argRes > 0)
            return 0;
        else
            return -argRes;
    }
    if (inputFile == "")
    {
        std::cout << "Missing brainfuck file input (source code).\nType bfpp --help to get more help.\n";
        return 2;
    }

    std::ofstream toCpp(intermediateFile);

    std::cout << "Converting brainfuck to C++...\n";
    bfToCpp code(inputFile);
    std::string codeStr = code.toStr();
    if (codeStr == "-1")
    {
        return 1;
    }
    // std::cout << codeStr;
    toCpp << codeStr;

    std::cout << "Compiling C++...\n";
    std::string compileCommand = "";
    compileCommand += "g++ " + intermediateFile + " -o " + outputFile;
    int result = std::system(compileCommand.c_str());

    if (!keepIntermediate)
    {
        std::cout << "Cleaning compilation files... ";
        std::string cleanCommand = "";
        cleanCommand += "rm " + intermediateFile;
        if (std::system(cleanCommand.c_str()) == 0)
            std::cout << "success\n";
        else
            std::cout << "fail\n";
    }

    if (result == 0)
    {
        std::cout << "Compilation successful." << std::endl;
    }
    else
    {
        std::cerr << "Compilation failed." << std::endl;
    }

    return 0;
}
