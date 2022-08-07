#include "MainLevel.h"

MainLevel::MainLevel()
{
    applicationFiles.push_back(ApplicationFile(sf::Vector2f(0.0f, 0.0f)));
}

void MainLevel::Update(float deltaTime)
{
    for (int i = 0; i < applicationFiles.size(); i++)
    {
        applicationFiles[i].Update(deltaTime);
    }
}

void MainLevel::Draw(sf::RenderWindow &window)
{
    for (int i = 0; i < applicationFiles.size(); i++)
    {
        applicationFiles[i].Draw(window);
    }
}
