#pragma once

#include <string>
#include <vector>

enum class InstructionType
{
    SetString,
    PrintString
};

class Instruction
{
public:

public:
    InstructionType instructionType;

    std::string stringLiteral;
};

class TerminalProgram
{
public:
    TerminalProgram();

    TerminalProgram(const std::vector<Instruction>& newInstructions);

    void SetInstructions(const std::vector<Instruction>& newInstructions);

    bool Execute(std::string& output);

private:
    std::vector<Instruction> instructions;

    int pc;

    std::string currentString;
};
