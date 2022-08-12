#include "TextFileInstance.h"

TextFileInstance::TextFileInstance(ResourceManager& resourceManager)
    :
    ApplicationInstance(sf::Vector2f(0.0f, 0.0f), 800, 600)
{
    text.setFont(resourceManager.GetFont("terminalFont"));

    SetTextWrapped("Hello, this is a game. A hopefully very fun game in the future.");
}

void TextFileInstance::Update(float deltaTime)
{
    ApplicationInstance::Update(deltaTime);

    text.setPosition(position);
}

void TextFileInstance::Draw(sf::RenderWindow &window)
{
    ApplicationInstance::Draw(window);

    window.draw(text);
}

void TextFileInstance::SetTextWrapped(const std::string& textContents)
{
    std::string accumulationContents = "";

    for (int i = 0; i < textContents.size(); i++)
    {
        accumulationContents += textContents[i];

        text.setString(accumulationContents);

        if (text.getGlobalBounds().width > width)
        {
            int spaceIndex = -1;

            for (int j = i; j >= 0; j--)
            {
                if (accumulationContents[j] == ' ')
                {
                    spaceIndex = j;

                    break;
                }
            }

            if (spaceIndex != -1)
            {
                accumulationContents[spaceIndex] = '\n';
            }

            else
            {
                char lastChar = accumulationContents[i];

                accumulationContents.pop_back();

                accumulationContents += '\n';

                accumulationContents += textContents[i];
            }
        }
    }
}
