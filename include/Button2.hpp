#pragma once
#include <SFML/Graphics.hpp>

class Button2 {
public:
    Button2(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& Textuer_dir);

    void draw(sf::RenderWindow& window);
    bool isClicked(const sf::Event& event, const sf::RenderWindow& window);
    bool get_status();
    void set_status(bool);
    void set_pos(const sf::Vector2f& pos);
    sf::Vector2f getPosButton();
private:
    sf::RectangleShape shape;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;
    bool selected = false;
};
