#include "ApplicationFile.h"

ApplicationFile::ApplicationFile(const sf::Vector2f& position, ApplicationInstanceType newApplicationInstanceType, ResourceManager& newResourceManager)
    :
    resourceManager(newResourceManager)
{
    rectangleShape.setPosition(position);
    rectangleShape.setSize(sf::Vector2f(64.0f, 64.0f));
    rectangleShape.setFillColor(sf::Color::White);

    applicationInstanceType = newApplicationInstanceType;
}

sf::FloatRect ApplicationFile::GetFloatRect()
{
    return rectangleShape.getGlobalBounds();
}

std::unique_ptr<ApplicationInstance> ApplicationFile::MakeApplicationInstance()
{
    switch (applicationInstanceType)
    {
        case ApplicationInstanceType::Base:
            return std::make_unique<ApplicationInstance>(sf::Vector2f(0.0f, 0.0f), 800, 600);
            break;

        case ApplicationInstanceType::Terminal:
            return std::make_unique<TerminalInstance>(TerminalInstance(resourceManager));
            break;

        case ApplicationInstanceType::TextFile:
            return std::make_unique<TextFileInstance>(resourceManager);
            break;
    }

    return std::make_unique<ApplicationInstance>(sf::Vector2f(0.0f, 0.0f), 800, 600);
}

void ApplicationFile::Update(float deltaTime)
{

}

void ApplicationFile::Draw(sf::RenderWindow& window)
{
    window.draw(rectangleShape);
}
