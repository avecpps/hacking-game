#pragma once

#include "TerminalApplication.h"

class TerminalApplicationEcho : public TerminalApplication
{
public:
    bool Execute(std::vector<std::string>& arguments, std::string& output, std::vector<TerminalApplicationType>& applicationTypes);
};
