#include "ApplicationFile.h"

ApplicationFile::ApplicationFile(const sf::Vector2f& position, std::unique_ptr<ApplicationInstance>&& newApplicationInstance)
{
    rectangleShape.setPosition(position);
    rectangleShape.setSize(sf::Vector2f(64.0f, 64.0f));
    rectangleShape.setFillColor(sf::Color::White);

    applicationInstance = std::move(newApplicationInstance);
}

sf::FloatRect ApplicationFile::GetFloatRect()
{
    return rectangleShape.getGlobalBounds();
}

std::unique_ptr<ApplicationInstance> ApplicationFile::MakeApplicationInstance()
{
    return std::make_unique<ApplicationInstance>(*applicationInstance);
}

void ApplicationFile::Update(float deltaTime)
{

}

void ApplicationFile::Draw(sf::RenderWindow& window)
{
    window.draw(rectangleShape);
}
