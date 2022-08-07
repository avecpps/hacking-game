#include "Game.h"

Game::Game(int width, int height, const std::string& title)
    :
    window(sf::VideoMode(width, height), title)
{
    applicationFiles.push_back(ApplicationFile(sf::Vector2f(0.0f, 0.0f)));
}

void Game::Start()
{
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        Update();

        Draw();
    }
}

void Game::Update()
{
    deltaTime = clock.restart().asMilliseconds();

    for (int i = 0; i < applicationFiles.size(); i++)
    {
        applicationFiles[i].Update(deltaTime);
    }
}

void Game::Draw()
{
    window.clear();

    for (int i = 0; i < applicationFiles.size(); i++)
    {
        applicationFiles[i].Draw(window);
    }

    window.display();
}
