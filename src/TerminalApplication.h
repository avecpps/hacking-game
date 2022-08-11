#pragma once

#include <string>
#include <vector>
#include <stack>
#include <memory>

enum class TerminalApplicationType
{
    Shell,
    Echo
};

class TerminalApplication
{
public:
    virtual void OnRestartApplication(std::string& output);

    virtual bool Execute(std::vector<std::string>& arguments, std::string& output, std::vector<TerminalApplicationType>& applicationTypes) = 0;

    virtual void OnTextEntered(char character, std::string& output, std::vector<TerminalApplicationType>& applicationTypes);
};
