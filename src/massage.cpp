#include "massage.hpp"
massage::massage(sf::Vector2f position, std::string output , sf::Color initcolor , int fontsize)
{
    this->position = position;
    this->output.setString(output);
    this->output.setPosition(position);
    if (!font.loadFromFile("../Horrified_Assets/creep.ttf"))
    {
        throw std::runtime_error("Could not load font");
    }
    this->output.setFont(font);
    this->output.setCharacterSize(fontsize);
    this->output.setFillColor(initcolor);
}
void massage::draw(sf::RenderWindow &window)
{
    window.draw(output);
}