#pragma once

#include <string>

class TerminalApplication
{
public:
    virtual bool Execute(std::string& output) = 0;

    virtual void OnTextEntered(char character, std::string& output);
};
