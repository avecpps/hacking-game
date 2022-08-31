#pragma once

#include <SFML/Graphics.hpp>

class Level
{
public:
    virtual void Update(float deltaTime, sf::RenderWindow& window) = 0;

    virtual void Draw(sf::RenderWindow& window) = 0;

    virtual void OnTextEntered(char character) = 0;

    virtual void OnMouseDragged(float x, float y);
};
