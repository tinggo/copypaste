#pragma once
#include <string>

class Rule
{
public:
    std::string name;
    std::string source;
    std::string destination;
    bool existPrompt;
    bool recurisive;
};