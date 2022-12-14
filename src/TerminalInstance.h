#pragma once

#include <memory>
#include <stack>
#include "ApplicationInstance.h"
#include "ResourceManager.h"
#include "TerminalProgram.h"

class TerminalInstance : public ApplicationInstance
{
public:
    TerminalInstance(ResourceManager& resourceManager);

    void Update(float deltaTime) override;

    void Draw(sf::RenderWindow& window) override;

    void OnTextEntered(char character) override;

private:
    sf::Text textBuffer;

    std::string terminalString;

    std::stack<TerminalProgram> programs;
};
