#pragma once
#include <string>

const std::string TAB("    ");

class bfppFunction
{
private:
    std::string name;
    std::string content;
    int height=1;
public:
    bfppFunction(std::string functionName);
    ~bfppFunction();
    std::string getName();
    std::string toStr();
    void addOB();
    bool addCB();
    void addPlus();
    void addMinus();
    void addLeft();
    void addRight();
    void addCin();
    void addCout();
    void addPause();
    void addDebug();
    void addExit();
    void addFunctionCall(std::string const &functionName);

    bool validFinalHeight();
};