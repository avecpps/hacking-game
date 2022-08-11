#pragma once

#include <vector>
#include "ApplicationFile.h"
#include "ApplicationInstance.h"
#include "Level.h"

class MainLevel : public Level
{
public:
    MainLevel();

    void Update(float deltaTime, sf::RenderWindow& window);

    void Draw(sf::RenderWindow& window);

private:
    bool IsHoveringOverInstance();

private:
    std::vector<ApplicationFile> applicationFiles;
    std::vector<std::unique_ptr<ApplicationInstance>> applicationInstances;

    sf::Clock mouseInteractClock;

    float mouseInteractDelay;

    bool hasClickedMouse;
    int mouseClickCount;

    bool hasClickedMouseDragging;

    sf::Vector2f mousePosition;
    sf::Vector2f previousMousePosition;

    sf::Vector2f newInstanceStartPosition;
};
