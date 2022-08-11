#pragma once

#include <SFML/Graphics.hpp>

class ApplicationInstance
{
public:
    ApplicationInstance(const sf::Vector2f& position, int newWidth, int newHeight);

    virtual void Update(float deltaTime);

    virtual void Draw(sf::RenderWindow& window);

protected:
    sf::RectangleShape topBorder;

    sf::RectangleShape background;

    int width;
    int height;
};
