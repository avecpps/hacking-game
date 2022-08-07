#pragma once

#include <SFML/Graphics.hpp>

class ApplicationFile
{
public:
    ApplicationFile(const sf::Vector2f& position);

    void Update(float deltaTime);

    void Draw(sf::RenderWindow& window);
private:
    sf::RectangleShape rectangleShape;
};
