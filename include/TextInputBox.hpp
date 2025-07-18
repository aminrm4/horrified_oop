#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class TextInputBox {
private:
    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;
    std::string input;
    bool isActive = false;

public:
    TextInputBox(sf::Vector2f position, sf::Vector2f size);

    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window ,  std::string massage);
    std::string getInput() const;
    void clear();
    sf::Vector2f getPos();
};

