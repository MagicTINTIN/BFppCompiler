#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <cstdlib>
#include <stack>
#include <cctype>
#include "bfppFunction.h"
#include "bfToCpp.h"

std::string genBaseFile()
{
    std::string rtn = "// File generated using Brainfuck++ Compiler\n";
    rtn += "#include <string>\n";
    rtn += "#include <vector>\n";
    rtn += "#include <iostream>\n";
    rtn += "#include <fstream>\n";
    rtn += "#include <sstream>\n";
    rtn += "#include <stdio.h>\n\n";

    
    rtn += "std::string memoryDelimiters(int const &memPos, int const &cursorPos)\n{\n";
    rtn += TAB + "if (memPos == cursorPos) return \" [ \";\n";
    rtn += TAB + "if (memPos - 1 == cursorPos) return \" ] \";\n";
    rtn += TAB + "else return \" | \";\n";
    rtn += "}\n";
    rtn += "void debugMemory(std::vector<unsigned char> &mem, int &position)\n{\n";
    rtn += TAB + "size_t i = 0;\n";
    rtn += TAB + "for (; i < mem.size(); i++)\n",
    rtn += TAB + "{\n";
    rtn += TAB + TAB + "std::cout << memoryDelimiters(i, position);\n";
    rtn += TAB + TAB + "std::cout << (unsigned int) mem[i];\n";
    rtn += TAB + "}\n";
    rtn += TAB + TAB + "std::cout << memoryDelimiters(i, position) << std::endl;\n";
    rtn += "}\n\n";

    rtn += "bool moveLeft(int &position)\n{\n";
    rtn += TAB + "if (position > 0) {position--; return false;}\n";
    rtn += TAB + "return true;\n";
    rtn += "}\n";
    rtn += "void moveRight(std::vector<unsigned char> &mem, int &position)\n{\n";
    rtn += TAB + "position++;\n";
    rtn += TAB + "if (position == mem.size()) mem.emplace_back(0);\n";
    rtn += "}\n\n";
    rtn += "const std::string ENTER_CHAR = \"\\nEnter a character > \";\n";
    rtn += "const std::string PAUSE_MSG = \"\\nPress [ENTER] to continue...\";\n";
    rtn += "const std::string RIGHT_ERROR_MSG = \"FATAL ERROR: Cursor can not go before position 0!\\n\";\n\n";
    return rtn;
}

/* BF TO CPP CONVERTER */

bfToCpp::bfToCpp(std::string fileName) : inputName(fileName)
{
    bfppFunction mainFunction("main");
    functions.emplace_back(mainFunction);

    std::fstream fromBf(fileName, std::fstream::in);

    if (!fromBf.is_open()) {
        fileNotFound = true;
        return;
    }

    std::ostringstream contentStream;
    contentStream << fromBf.rdbuf();
    std::string fileContent = contentStream.str();

    size_t nbFuctions = 1;
    std::stack<unsigned int> fctIds;
    fctIds.push(0);
    for (size_t charNb = 0; charNb < fileContent.size(); charNb++)
    {
        const char ch = fileContent[charNb];
        if (ch == '[') functions[fctIds.top()].addOB();
        else if (ch == ']') functions[fctIds.top()].addCB();
        else if (ch == '+') functions[fctIds.top()].addPlus();
        else if (ch == '-') functions[fctIds.top()].addMinus();
        else if (ch == '<') functions[fctIds.top()].addLeft();
        else if (ch == '>') functions[fctIds.top()].addRight();
        else if (ch == '.') functions[fctIds.top()].addCout();
        else if (ch == ',') functions[fctIds.top()].addCin();
        else if (ch == '!') functions[fctIds.top()].addPause();
        else if (ch == '?') functions[fctIds.top()].addDebug();
        else if (ch == '*') functions[fctIds.top()].addExit();
        else if (ch == '\\') {
            std::string fctName;
            charNb++;
            while (fileContent[charNb] != '\\' && std::isalpha(fileContent[charNb]))
            {
                fctName += fileContent[charNb];
                charNb++;
            }
            if (fileContent[charNb] != '\\') {
                errorString = "The function \"" + fctName + "\" is not correctly defined, expected \"\\\" at the end of the name declaration";
                return;
            }
        }
    }
    
}

bfToCpp::~bfToCpp()
{
}

std::string bfToCpp::toStr()
{
    if (fileNotFound) {
        std::cerr << "Error opening Brainfuck++ file: " << inputName << std::endl;
        return "-1";
    }
    if (errorString != "") {
        std::cerr << "Compilation failed: " << errorString << std::endl;
        return "-1";
    }

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