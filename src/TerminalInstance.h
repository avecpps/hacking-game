#pragma once

#include "ApplicationInstance.h"
#include "ResourceManager.h"

class TerminalInstance : public ApplicationInstance
{
public:
    TerminalInstance(ResourceManager& resourceManager);

    void Update(float deltaTime) override;

    void Draw(sf::RenderWindow& window) override;

    void OnTextEntered(char character) override;

private:
    sf::Text textBuffer;

    std::string input;
};
