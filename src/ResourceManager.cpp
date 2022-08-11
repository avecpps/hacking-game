#include "ResourceManager.h"

void ResourceManager::LoadFont(const std::string &name, const std::string &filepath)
{
    fonts[name].loadFromFile(filepath);
}

sf::Font& ResourceManager::GetFont(const std::string &name)
{
    return fonts[name];
}
