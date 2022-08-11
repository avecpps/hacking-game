#include "MainLevel.h"

MainLevel::MainLevel()
{
    applicationFiles.push_back(ApplicationFile(sf::Vector2f(0.0f, 0.0f), std::make_unique<ApplicationInstance>(ApplicationInstance(sf::Vector2f(20.0f, 20.0f), 200, 150))));

    mouseInteractDelay = 1.0f;

    hasClickedMouse = false;

    mouseClickCount = 0;

    newInstanceStartPosition = sf::Vector2f(64.0f, 64.0f);
}

void MainLevel::Update(float deltaTime, sf::RenderWindow& window)
{
    previousMousePosition = mousePosition;
    mousePosition = (sf::Vector2f)sf::Mouse::getPosition(window);

    if (mouseInteractClock.getElapsedTime().asSeconds() >= mouseInteractDelay)
    {
        mouseClickCount = 0;

        mouseInteractClock.restart();
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        if (!hasClickedMouse)
        {
            for (int i = 0; i < applicationFiles.size(); i++)
            {
                if (applicationFiles[i].GetFloatRect().contains(mousePosition) && !IsHoveringOverInstance())
                {
                    mouseClickCount += 1;

                    if (mouseClickCount == 2)
                    {
                        applicationInstances.push_back(applicationFiles[i].MakeApplicationInstance());
                        applicationInstances[applicationInstances.size() - 1]->SetPosition(newInstanceStartPosition);

                        newInstanceStartPosition = sf::Vector2f(64.0f, 64.0f);

                        mouseClickCount = 0;
                    }
                }
            }

            for (int i = applicationInstances.size() - 1; i >= 0; i--)
            {
                if (applicationInstances[i]->GetFloatRect().contains(mousePosition) && !hasClickedMouse)
                {
                    if (i != applicationInstances.size() - 1)
                    {
                        applicationInstances.push_back(std::move(applicationInstances[i]));
                        applicationInstances.erase(applicationInstances.begin() + i);
                    }

                    break;
                }
            }
        }

        hasClickedMouse = true;
    }

    else
    {
        hasClickedMouse = false;
    }

    for (int i = 0; i < applicationFiles.size(); i++)
    {
        applicationFiles[i].Update(deltaTime);
    }

    for (int i = applicationInstances.size() - 1; i >= 0; i--)
    { 
        if (applicationInstances[i]->HandleDragging(mousePosition, previousMousePosition))
        {
            if (i != applicationInstances.size() - 1)
            {
                applicationInstances.push_back(std::move(applicationInstances[i]));
                applicationInstances.erase(applicationInstances.begin() + i);
            }

            hasClickedMouse = true;

            break;
        }

        if (applicationInstances[i]->GetFloatRect().contains(mousePosition))
        {
            break;
        }
    }

    for (int i = 0; i < applicationInstances.size(); i++)
    {
        applicationInstances[i]->Update(deltaTime);
    }
}

void MainLevel::Draw(sf::RenderWindow &window)
{
    for (int i = 0; i < applicationFiles.size(); i++)
    {
        applicationFiles[i].Draw(window);
    }

    for (int i = 0; i < applicationInstances.size(); i++)
    {
        applicationInstances[i]->Draw(window);
    }
}

bool MainLevel::IsHoveringOverInstance()
{
    for (int i = applicationInstances.size() - 1; i >= 0; i--)
    {
        if (applicationInstances[i]->GetFloatRect().contains(mousePosition))
        {
            return true;
        }
    }

    return false;
}
