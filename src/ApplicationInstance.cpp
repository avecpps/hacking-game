#include "ApplicationInstance.h"

ApplicationInstance::ApplicationInstance(const sf::Vector2f& position, int newWidth, int newHeight)
{
    width = newWidth;
    height = newHeight;

    borderThickness = 10.0f;

    topBorder.setFillColor(sf::Color::Cyan);
    background.setFillColor(sf::Color::Black);

    topBorder.setSize(sf::Vector2f(width, borderThickness));
    background.setSize(sf::Vector2f(width, height));

    topBorder.setPosition(position - sf::Vector2f(0.0f, borderThickness));
    background.setPosition(position);

}

void ApplicationInstance::SetPosition(const sf::Vector2f &newPosition)
{
    position = newPosition;

    UpdateWindowPosition();
}

void ApplicationInstance::Update(float deltaTime)
{

}

void ApplicationInstance::Draw(sf::RenderWindow &window)
{
    window.draw(topBorder);

    window.draw(background);
}

void ApplicationInstance::UpdateWindowPosition()
{
    topBorder.setPosition(position - sf::Vector2f(0.0f, borderThickness));
    background.setPosition(position);
}
