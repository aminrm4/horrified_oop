#include "Button.hpp"
#include <SFML/Audio.hpp>
#include <stdexcept>
#include <iostream>
#include <thread>
#include "free_func.hpp"

Button::Button(const sf::Vector2f &size, const sf::Vector2f &position, const std::string &text)
{
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(sf::Color(100, 100, 250)); 
    this->position = position;
    if (!font.loadFromFile("../Horrified_Assets/creep.ttf"))
    {
        throw std::runtime_error("Could not load font");
    }

    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(20);
    label.setFillColor(sf::Color::White);

    sf::FloatRect textBounds = label.getLocalBounds();
    label.setOrigin(textBounds.width / 2, textBounds.height / 2);
    label.setPosition(
        position.x + size.x / 2,
        position.y + size.y / 2 - 5 
    );
}

void Button::draw(sf::RenderWindow &window)
{
    window.draw(shape);
    window.draw(label);
}

bool Button::isClicked(const sf::Event &event, const sf::RenderWindow &window)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
        {
            std::thread t(playSound ,"../sounds/MouseClick.mp3");
                t.detach();
            
            return true;
        }
    }
    return false;
}

sf::Vector2f Button::getPosButton()
{
    return position;
}
