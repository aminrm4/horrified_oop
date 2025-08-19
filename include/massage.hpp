#pragma once 
#include <SFML/Graphics.hpp>
#include <string>

class massage
{
    sf::Text output;
    sf::Font font;
    sf::Color color;
    sf::Vector2f position;

    public:
    massage() = default;
    massage(sf::Vector2f position , std::string output , sf::Color color ,int fontsize);
    void draw(sf::RenderWindow& window);
    void set_massage(std::string massage);

};