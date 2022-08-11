#include "TerminalApplicationShell.h"

TerminalApplicationShell::TerminalApplicationShell(std::string& output)
{
    output += "shell: ";
}

bool TerminalApplicationShell::Execute(std::string &output)
{
    return false;
}

void TerminalApplicationShell::OnTextEntered(char character, std::string& output)
{ 
    if (character == '\b')
    {
        output.pop_back();

        inputLine.pop_back();
    }

    else if (character == '\r')
    {
        output += "\nshell: ";

        inputLine.clear();
    }

    else
    {
        output += character;

        inputLine += character;
    }
}
