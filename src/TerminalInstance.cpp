#include "TerminalInstance.h"

TerminalInstance::TerminalInstance()
    :
    ApplicationInstance(sf::Vector2f(0.0f, 0.0f), 800, 600)
{
}

void TerminalInstance::Update(float deltaTime)
{
    ApplicationInstance::Update(deltaTime);
}

void TerminalInstance::Draw(sf::RenderWindow &window)
{
    ApplicationInstance::Draw(window);
}
