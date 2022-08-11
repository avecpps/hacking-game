#include "TerminalApplicationShell.h"

TerminalApplicationShell::TerminalApplicationShell(std::string& output)
{
    output += "shell: ";

    shouldClose = false;
}

void TerminalApplicationShell::OnRestartApplication(std::string& output)
{
    output += "\nshell: ";
}

bool TerminalApplicationShell::Execute(std::vector<std::string>& arguments, std::string &output, std::vector<TerminalApplicationType>& applicationTypes)
{
    arguments = newArguments;

    return shouldClose;
}

void TerminalApplicationShell::OnTextEntered(char character, std::string& output, std::vector<TerminalApplicationType>& applicationTypes)
{ 
    if (character == '\b')
    {
        output.pop_back();

        inputLine.pop_back();
    }

    else if (character == '\r')
    {
        std::pair<std::string, std::vector<std::string>> pair = ParseCommand(inputLine);

        if (pair.first == "echo")
        {
            newArguments = pair.second;

            applicationTypes.push_back(TerminalApplicationType::Echo);

            inputLine.clear();

            return;
        }


        if (inputLine == "exit")
        {
            shouldClose = true;
        }

        else
        {
            output += "\nshell: ";
        }

        inputLine.clear();
    }

    else
    {
        output += character;

        inputLine += character;
    }
}

std::pair<std::string, std::vector<std::string>> TerminalApplicationShell::ParseCommand(const std::string& command)
{
    std::string first = "";

    std::vector<std::string> second;

    bool accumulatingFirst = true;

    std::string current = "";

    for (int i = 0; i < command.size(); i++)
    {
        if (accumulatingFirst)
        {
            if (command[i] != ' ')
            {
                first += command[i];
            }

            else
            {
                accumulatingFirst = false;
            }
        }

        else
        {
            if (command[i] != ' ')
            {
                current += command[i];
            }

            else
            {
                second.push_back(current);

                current.clear();
            }
        }
    }

    second.push_back(current);

    return { first, second };
}
