#pragma once

#include <vector>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "ApplicationFile.h"
#include "Level.h"
#include "MainLevel.h"

class Game
{
public:
    Game(int width, int height, const std::string& title);

    void Start();

    void Update();

    void Draw();

private:
    sf::RenderWindow window;

    sf::Clock clock;

    float deltaTime;

    std::vector<std::unique_ptr<Level>> levels;

    int currentLevel;
};
