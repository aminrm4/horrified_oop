#pragma once
#include <SFML/Graphics.hpp>

class Button {
public:
    Button(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& text);

    void draw(sf::RenderWindow& window);
    bool isClicked(const sf::Event& event, const sf::RenderWindow& window);
    sf::Vector2f getPosButton();
private:
    sf::RectangleShape shape;
    sf::Font font;
    sf::Text label;
    sf::Vector2f position;
};
