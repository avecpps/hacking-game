#include "ApplicationInstance.h"

ApplicationInstance::ApplicationInstance(const sf::Vector2f& position, int newWidth, int newHeight)
{
    width = newWidth;
    height = newHeight;

    topBorder.setFillColor(sf::Color::Cyan);
    background.setFillColor(sf::Color::Black);

    topBorder.setSize(sf::Vector2f(width, 10.0f));
    background.setSize(sf::Vector2f(width, height));

    topBorder.setPosition(position - sf::Vector2f(0.0f, 10.0f));
    background.setPosition(position);
}

void ApplicationInstance::Update(float deltaTime)
{

}

void ApplicationInstance::Draw(sf::RenderWindow &window)
{
    window.draw(topBorder);

    window.draw(background);
}
