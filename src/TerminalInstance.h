#pragma once

#include "ApplicationInstance.h"

class TerminalInstance : public ApplicationInstance
{
public:
    TerminalInstance();

    void Update(float deltaTime) override;

    void Draw(sf::RenderWindow& window) override;

private:
    sf::Text textBuffer;
};
