#pragma once

#include <SFML/Graphics.hpp>

class ApplicationInstance
{
public:
    ApplicationInstance(const sf::Vector2f& newPosition, int newWidth, int newHeight);

    sf::FloatRect GetFloatRect();

    void SetPosition(const sf::Vector2f& newPosition);
    sf::Vector2f GetPosition();

    bool HandleDragging(const sf::Vector2f& mousePosition, const sf::Vector2f& previousMousePosition);

    virtual void Update(float deltaTime);

    virtual void Draw(sf::RenderWindow& window);

    virtual void OnTextEntered(char character);

    void SetIsDragging(bool newIsDragging);

    bool GetIsDragging();


    void SetFocused(bool newFocused);

protected:
    void UpdateWindowPosition();

protected:
    sf::RectangleShape topBorder;

    sf::RectangleShape background;

    int width;
    int height;

    sf::Vector2f position;

    float borderThickness;

    bool isDragging;

    bool isFocused;
};
