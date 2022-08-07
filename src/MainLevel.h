#pragma once

#include <vector>
#include "ApplicationFile.h"
#include "Level.h"

class MainLevel : public Level
{
public:
    MainLevel();

    void Update(float deltaTime);

    void Draw(sf::RenderWindow& window);

private:
    std::vector<ApplicationFile> applicationFiles;
};
