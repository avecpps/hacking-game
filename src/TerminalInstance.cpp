#include "TerminalInstance.h"

TerminalInstance::TerminalInstance(ResourceManager& resourceManager)
    :
    ApplicationInstance(sf::Vector2f(0.0f, 0.0f), 800, 600)
{
    textBuffer.setFont(resourceManager.GetFont("terminalFont"));

    textBuffer.setCharacterSize(25);
    textBuffer.setString("Hello World");

    textBuffer.setFillColor(sf::Color::White);
}

void TerminalInstance::Update(float deltaTime)
{
    ApplicationInstance::Update(deltaTime);

    textBuffer.setPosition(position);
}

void TerminalInstance::Draw(sf::RenderWindow &window)
{
    ApplicationInstance::Draw(window);

    window.draw(textBuffer);
}
