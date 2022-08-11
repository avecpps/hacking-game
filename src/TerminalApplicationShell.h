#pragma once

#include "TerminalApplication.h"

class TerminalApplicationShell : public TerminalApplication
{
public:
    TerminalApplicationShell(std::string& output);

    bool Execute(std::string& output) override;

    void OnTextEntered(char character, std::string& output) override;

private:
    std::string inputLine;
};
