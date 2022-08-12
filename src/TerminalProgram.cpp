#include "TerminalProgram.h"


TerminalProgram::TerminalProgram()
{
    pc = 0;
}

TerminalProgram::TerminalProgram(const std::vector<Instruction>& newInstructions)
{
    instructions = newInstructions;

    pc = 0;
}

void TerminalProgram::SetInstructions(const std::vector<Instruction> &newInstructions)
{
    instructions = newInstructions;
}

bool TerminalProgram::Execute(std::string &output)
{
    switch (instructions[pc].instructionType)
    {
        case InstructionType::SetString:
            currentString = instructions[pc].stringLiteral;
            break;

        case InstructionType::PrintString:
            output += currentString;
            break;
    }

    pc++;

    return pc == instructions.size();
}
