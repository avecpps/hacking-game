#include "Game.h"

Game::Game(int width, int height, const std::string& title)
    :
    window(sf::VideoMode(width, height), title)
{
    resourceManager.LoadFont("terminalFont", "../font.ttf");

    levels.push_back(std::make_unique<MainLevel>(resourceManager));

    currentLevel = 0;

    window.setVerticalSyncEnabled(true);
}

void Game::Start()
{
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleRegion(0.0f, 0.0f, event.size.width, event.size.height);

                window.setView(sf::View(visibleRegion));
            }

            else if (event.type == sf::Event::Closed)
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

    levels[currentLevel]->Update(deltaTime, window);
}

void Game::Draw()
{
    window.clear(sf::Color(20.0f, 20.0f, 20.0f));

    levels[currentLevel]->Draw(window);

    window.display();
}
