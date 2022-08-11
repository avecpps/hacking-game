#include "TerminalInstance.h"

TerminalInstance::TerminalInstance(ResourceManager& resourceManager)
    :
    ApplicationInstance(sf::Vector2f(0.0f, 0.0f), 800, 600)
{
    textBuffer.setFont(resourceManager.GetFont("terminalFont"));

    textBuffer.setCharacterSize(25);
    textBuffer.setString("Hello World");

    textBuffer.setFillColor(sf::Color::White);

    terminalApplications.push(std::make_unique<TerminalApplicationShell>(terminalString));

    textBuffer.setString(terminalString);
}

void TerminalInstance::Update(float deltaTime)
{
    ApplicationInstance::Update(deltaTime);

    if (terminalApplications.size() != 0)
    {
        if (terminalApplications.top()->Execute(arguments, terminalString, applicationTypes))
        {
            terminalApplications.pop();

            if (terminalApplications.size() != 0)
            {
                terminalApplications.top()->OnRestartApplication(terminalString);
            }
        }

        for (int i = 0; i < applicationTypes.size(); i++)
        {
            switch (applicationTypes[i])
            {
                case TerminalApplicationType::Shell:
                    terminalApplications.push(std::make_unique<TerminalApplicationShell>(terminalString));
                    break;

                case TerminalApplicationType::Echo:
                    terminalApplications.push(std::make_unique<TerminalApplicationEcho>());
                    break;
            }
        }

        applicationTypes.clear();
    }

    else
    {
        shouldClose = true;
    }

    textBuffer.setString(terminalString);

    textBuffer.setPosition(position);
}

void TerminalInstance::Draw(sf::RenderWindow &window)
{
    ApplicationInstance::Draw(window);

    window.draw(textBuffer);
}

void TerminalInstance::OnTextEntered(char character)
{
    if (terminalApplications.size() != 0)
    {
        terminalApplications.top()->OnTextEntered(character, terminalString, applicationTypes);
    }
}
