#include "ApplicationInstance.h"
#include "ResourceManager.h"

class TextFileInstance : public ApplicationInstance
{
public:
    TextFileInstance(ResourceManager& resourceManager);

    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);

private:
    void SetTextWrapped(const std::string& textContents);

private:
    sf::Text text;
};
