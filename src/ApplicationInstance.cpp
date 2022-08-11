#include "ApplicationInstance.h"

ApplicationInstance::ApplicationInstance(const sf::Vector2f& newPosition, int newWidth, int newHeight)
{
    width = newWidth;
    height = newHeight;

    borderThickness = 20.0f;

    topBorder.setFillColor(sf::Color::Cyan);
    background.setFillColor(sf::Color::Black);

    position = newPosition;

    topBorder.setSize(sf::Vector2f(width, borderThickness));
    background.setSize(sf::Vector2f(width, height));

    UpdateWindowPosition();

    isDragging = false;
}

sf::FloatRect ApplicationInstance::GetFloatRect()
{
    return background.getGlobalBounds();
}

void ApplicationInstance::SetPosition(const sf::Vector2f &newPosition)
{
    position = newPosition;

    UpdateWindowPosition();
}

sf::Vector2f ApplicationInstance::GetPosition()
{
    return position;
}

bool ApplicationInstance::HandleDragging(const sf::Vector2f &mousePosition, const sf::Vector2f &previousMousePosition)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && topBorder.getGlobalBounds().contains(previousMousePosition))
    {
        position += mousePosition - previousMousePosition;

        UpdateWindowPosition();
        
        return true;
    }

    return false;
}

void ApplicationInstance::Update(float deltaTime)
{
}

void ApplicationInstance::Draw(sf::RenderWindow &window)
{
    window.draw(topBorder);

    window.draw(background);
}

void ApplicationInstance::SetIsDragging(bool newIsDragging)
{
    isDragging = newIsDragging;
}

bool ApplicationInstance::GetIsDragging()
{
    return isDragging;
}

void ApplicationInstance::UpdateWindowPosition()
{
    topBorder.setPosition(position - sf::Vector2f(0.0f, borderThickness));
    background.setPosition(position);
}
