#include "Game.h"

Game::Game(int width, int height, const std::string& title)
    :
    window(sf::VideoMode(width, height), title)
{

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
}

void Game::Draw()
{
    window.clear();

    window.display();
}
