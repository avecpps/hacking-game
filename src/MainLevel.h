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
    std::vector<ApplicationFile> applicationFiles;
    std::vector<std::unique_ptr<ApplicationInstance>> applicationInstances;

    sf::Clock mouseInteractClock;

    float mouseInteractDelay;

    bool hasClickedMouse;
    int mouseClickCount;

    sf::Vector2f mousePosition;
};