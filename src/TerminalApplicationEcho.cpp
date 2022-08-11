#include "TerminalApplicationEcho.h"

bool TerminalApplicationEcho::Execute(std::vector<std::string> &arguments, std::string &output, std::vector<TerminalApplicationType>& applicationTypes)
{
    output += '\n';

    if (arguments.size() != 0)
    {
        output += arguments[0];
    }


    return true;
}
