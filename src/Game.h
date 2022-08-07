#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "ApplicationFile.h"

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

    std::vector<ApplicationFile> applicationFiles;
};
