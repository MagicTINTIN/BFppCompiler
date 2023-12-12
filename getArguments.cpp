#include <string>
#include <vector>
#include <iostream>
#include "getArguments.h"

void replaceFirst(std::string &s, std::string const &toReplace, std::string const &replaceWith)
{
    std::size_t pos = s.find(toReplace);
    if (pos == std::string::npos)
        return;
    s.replace(pos, toReplace.length(), replaceWith);
}

int getArguments(std::string const &version, std::vector<std::string> args, std::string &inputfile, std::string &intermediatefile, std::string &outputfile, bool &intermediate)
{
    for (size_t i = 0; i < args.size(); ++i)
    {
        if (args[i] == "--intermediate" || args[i] == "-i")
            intermediate = true;
        else if (args[i] == "-o")
        {
            if (i + 1 < args.size())
            {
                outputfile = args[i + 1];
                i++;
            }
            else
            {
                std::cout << "--o needs to be followed by the name of output file" << std::endl;
                return -1;
            }
        }
        else if (args[i] == "--version" || args[i] == "-v")
        {
            std::cout << "bfpp version: " << version << std::endl;
            return 1;
        }
        else if (args[i] == "--help" || args[i] == "-h")
        {
            std::cout << "bfpp is a compiler for Brainfuck++" << std::endl
                      << "usage: bfpp filetocompile.bf [options]" << std::endl
                      << std::endl
                      << "Available options" << std::endl
                      << " -i, --intermediate   Keep intermediate cpp file" << std::endl
                      << " -o outputfilename    Specify the name of the output file" << std::endl;
            return 1;
        }
        else
        {
            inputfile = args[i];
            if (outputfile == "")
            {
                outputfile = inputfile;
                replaceFirst(outputfile, ".bf", "");
                intermediatefile = outputfile;
                outputfile += ".o";
                intermediatefile += ".o";
            }

            intermediatefile = inputfile;
            replaceFirst(intermediatefile, ".bf", "");
            intermediatefile += ".cpp";
        }
    }
    return 0;
}