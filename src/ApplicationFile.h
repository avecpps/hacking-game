#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "ApplicationInstance.h"

class ApplicationFile
{
public:
    ApplicationFile(const sf::Vector2f& position, std::unique_ptr<ApplicationInstance>&& newApplicationInstance);

    sf::FloatRect GetFloatRect();

    std::unique_ptr<ApplicationInstance> MakeApplicationInstance();

    void Update(float deltaTime);

    void Draw(sf::RenderWindow& window);
private:
    sf::RectangleShape rectangleShape;

    std::unique_ptr<ApplicationInstance> applicationInstance;
};
