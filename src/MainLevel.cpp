#include "MainLevel.h"

MainLevel::MainLevel(ResourceManager& resourceManager)
{
    applicationFiles.push_back(ApplicationFile(sf::Vector2f(0.0f, 0.0f), ApplicationInstanceType::Base, resourceManager));
    applicationFiles.push_back(ApplicationFile(sf::Vector2f(0.0f, 96.0f), ApplicationInstanceType::Terminal, resourceManager));

    mouseInteractDelay = 1.0f;

    hasClickedMouse = false;

    mouseClickCount = 0;

    newInstanceStartPosition = sf::Vector2f(64.0f, 64.0f);

    isDragging = false;
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

    for (int i = applicationInstances.size() - 1; i >= 0; i--)
    { 
        if (!hasClickedMouse || isDragging)
        {
            if (applicationInstances[i]->HandleDragging(mousePosition, previousMousePosition))
            {
                if (i != applicationInstances.size() - 1)
                {
                    applicationInstances[applicationInstances.size() - 1]->SetFocused(false);

                    applicationInstances.push_back(std::move(applicationInstances[i]));
                    applicationInstances.erase(applicationInstances.begin() + i);

                    applicationInstances[applicationInstances.size() - 1]->SetFocused(true);
                }

                hasClickedMouse = true;

                isDragging = true;

                break;
            }

            isDragging = false;

            if (applicationInstances[i]->GetFloatRect().contains(mousePosition))
            {
                break;
            }

        }

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
                        if (applicationInstances.size() != 0)
                        {
                            applicationInstances[applicationInstances.size() - 1]->SetFocused(false);
                        }

                        applicationInstances.push_back(applicationFiles[i].MakeApplicationInstance());
                        applicationInstances[applicationInstances.size() - 1]->SetPosition(newInstanceStartPosition);

                        applicationInstances[applicationInstances.size() - 1]->SetFocused(true);

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
                        applicationInstances[applicationInstances.size() - 1]->SetFocused(false);

                        applicationInstances.push_back(std::move(applicationInstances[i]));
                        applicationInstances.erase(applicationInstances.begin() + i);

                        applicationInstances[applicationInstances.size() - 1]->SetFocused(true);
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

    for (int i = 0; i < applicationInstances.size(); i++)
    {
        applicationInstances[i]->Update(deltaTime);

        if (applicationInstances[i]->GetShouldClose())
        {
            applicationInstances.erase(applicationInstances.begin() + i);

            i--;
        }
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

void MainLevel::OnTextEntered(char character)
{
    if (applicationInstances.size() != 0)
    {
        applicationInstances[applicationInstances.size() - 1]->OnTextEntered(character);
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
