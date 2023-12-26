#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <cstdlib>
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
    rtn += TAB + TAB + "std::cout << memoryDelimiters(i, position);";
    rtn += TAB + TAB + "std::cout << (unsigned int) mem[i];";
    rtn += TAB + "}\n";
    rtn += TAB + TAB + "std::cout << memoryDelimiters(i, position) << std::endl;";
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

    size_t fctNb = 0;
    for (size_t charNb = 0; charNb < fileContent.size(); charNb++)
    {
        const char ch = fileContent[charNb];
        if (ch == '[') functions[fctNb].addOB();
        else if (ch == ']') functions[fctNb].addCB();
        else if (ch == '+') functions[fctNb].addPlus();
        else if (ch == '-') functions[fctNb].addMinus();
        else if (ch == '<') functions[fctNb].addLeft();
        else if (ch == '>') functions[fctNb].addRight();
        else if (ch == '.') functions[fctNb].addCout();
        else if (ch == ',') functions[fctNb].addCin();
        else if (ch == '!') functions[fctNb].addPause();
        else if (ch == '?') functions[fctNb].addDebug();
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