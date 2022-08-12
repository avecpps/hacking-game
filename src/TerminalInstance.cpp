#include "TerminalInstance.h"

TerminalInstance::TerminalInstance(ResourceManager& resourceManager)
    :
    ApplicationInstance(sf::Vector2f(0.0f, 0.0f), 800, 600)
{
    textBuffer.setFont(resourceManager.GetFont("terminalFont"));

    textBuffer.setCharacterSize(25);

    textBuffer.setFillColor(sf::Color::White);

    terminalString = "Terminal\n\n";

    textBuffer.setString(terminalString);

    std::vector<Instruction> programCode;

    Instruction instruction1;

    instruction1.instructionType = InstructionType::SetString;
    instruction1.stringLiteral = "Hello World";

    Instruction instruction2;

    instruction2.instructionType = InstructionType::PrintString;

    programCode.push_back(instruction1);
    programCode.push_back(instruction2);

    programs.push(TerminalProgram(programCode));
}

void TerminalInstance::Update(float deltaTime)
{
    ApplicationInstance::Update(deltaTime);

    if (programs.size() != 0)
    {
        if (programs.top().Execute(terminalString))
        {
            programs.pop();
        }
    }

    textBuffer.setString(terminalString);

    textBuffer.setPosition(position);
}

void TerminalInstance::Draw(sf::RenderWindow &window)
{
    ApplicationInstance::Draw(window);

    window.draw(textBuffer);
}

void TerminalInstance::OnTextEntered(char character)
{

}
