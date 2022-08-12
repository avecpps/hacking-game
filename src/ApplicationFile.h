#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "ApplicationInstance.h"
#include "TerminalInstance.h"
#include "TextFileInstance.h"

enum class ApplicationInstanceType
{
    Base,
    Terminal,
    TextFile
};

class ApplicationFile
{
public:
    ApplicationFile(const sf::Vector2f& position, ApplicationInstanceType newApplicationInstanceType, ResourceManager& newResourceManager);

    sf::FloatRect GetFloatRect();

    std::unique_ptr<ApplicationInstance> MakeApplicationInstance();

    void Update(float deltaTime);

    void Draw(sf::RenderWindow& window);

private:
    sf::RectangleShape rectangleShape;

    ApplicationInstanceType applicationInstanceType;

    ResourceManager& resourceManager;
};
