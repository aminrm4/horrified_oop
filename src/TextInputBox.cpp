#include "TextInputBox.hpp"
#include "massage.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include <thread>
#include <stdexcept>
#include "free_func.hpp"

TextInputBox::TextInputBox(sf::Vector2f position, sf::Vector2f size)
{
    if (!font.loadFromFile("../Horrified_Assets/arial.ttf"))
    {
        throw std::runtime_error("Failed to load font");
    }

    box.setPosition(position);
    box.setSize(size);
    box.setFillColor(sf::Color::White);
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(2);

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(position.x + 5, position.y + 5);
}

void TextInputBox::handleEvent(const sf::Event &event, const sf::RenderWindow &window)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        auto mousePos = sf::Mouse::getPosition(window);
        auto worldPos = window.mapPixelToCoords(mousePos);

        if (box.getGlobalBounds().contains(worldPos))
        {
            isActive = true;
            std::thread t(playSound, "../sounds/MouseClick.mp3");
            t.detach();
            box.setOutlineColor(sf::Color::Blue);
        }
        else
        {
            isActive = false;
            box.setOutlineColor(sf::Color::Transparent);
        }
    }

    if (isActive && event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode == 8)
        {
            if (!input.empty())
                input.pop_back();
        }
        else if (event.text.unicode >= 32 && event.text.unicode < 128)
        {
            input += static_cast<char>(event.text.unicode);
        }
        text.setString(input);
    }
}

void TextInputBox::draw(sf::RenderWindow &window, std::string massage)
{
    window.draw(box);
    if (text.getString().getSize() == 0)
    {
        class massage temp({box.getPosition().x + 5, box.getPosition().y + 5}, massage, sf::Color(50, 50, 50, 255), 30);
        temp.draw(window);
    }
    else
        window.draw(text);
}

std::string TextInputBox::getInput() const
{
    return input;
}

void TextInputBox::clear()
{
    input.clear();
    text.setString("");
}
sf::Vector2f TextInputBox::getPos()
{
    return box.getPosition();
}
