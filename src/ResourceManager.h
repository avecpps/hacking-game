#pragma once

#include <string>
#include <map>
#include <SFML/Graphics.hpp>

class ResourceManager
{
public:
    void LoadFont(const std::string& name, const std::string& filepath);

    sf::Font& GetFont(const std::string& name);

private:
    std::map<std::string, sf::Font> fonts;
};
