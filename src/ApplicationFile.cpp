#include "ApplicationFile.h"

ApplicationFile::ApplicationFile(const sf::Vector2f& position)
{
    rectangleShape.setPosition(position);
    rectangleShape.setSize(sf::Vector2f(64.0f, 64.0f));
    rectangleShape.setFillColor(sf::Color::White);
}

void ApplicationFile::Update(float deltaTime)
{

}

void ApplicationFile::Draw(sf::RenderWindow& window)
{
    window.draw(rectangleShape);
}
