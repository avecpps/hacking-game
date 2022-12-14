#pragma once

#include <vector>
#include "ApplicationFile.h"
#include "ApplicationInstance.h"
#include "TerminalInstance.h"
#include "ResourceManager.h"
#include "Level.h"

class MainLevel : public Level
{
public:
    MainLevel(ResourceManager& resourceManager);

    void Update(float deltaTime, sf::RenderWindow& window) override;

    void Draw(sf::RenderWindow& window) override;

    void OnTextEntered(char character) override;

private:
    bool IsHoveringOverInstance();

private:
    std::vector<ApplicationFile> applicationFiles;
    std::vector<std::unique_ptr<ApplicationInstance>> applicationInstances;

    sf::Clock mouseInteractClock;

    float mouseInteractDelay;

    bool hasClickedMouse;
    int mouseClickCount;

    bool isDragging;


    bool hasClickedMouseDragging;

    sf::Vector2f mousePosition;
    sf::Vector2f previousMousePosition;

    sf::Vector2f newInstanceStartPosition;
};
