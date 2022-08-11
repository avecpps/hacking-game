#pragma once

#include "TerminalApplicationEcho.h"
#include "TerminalApplication.h"

class TerminalApplicationShell : public TerminalApplication
{
public:
    TerminalApplicationShell(std::string& output);

    void OnRestartApplication(std::string& output) override;

    bool Execute(std::vector<std::string>& arguments, std::string& output, std::vector<TerminalApplicationType>& applicationTypes) override;

    void OnTextEntered(char character, std::string& output, std::vector<TerminalApplicationType>& applicationTypes) override;

private:
    std::pair<std::string, std::vector<std::string>> ParseCommand(const std::string& command);

private:
    std::string inputLine;

    bool shouldClose;

    std::vector<std::string> newArguments;
};
