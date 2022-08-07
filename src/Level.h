#pragma once

#include <SFML/Graphics.hpp>

class Level
{
public:
    virtual void Update(float deltaTime) = 0;

    virtual void Draw(sf::RenderWindow& window) = 0;
};
