#include "Button.hpp"

Button::Button(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& text) {
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(sf::Color(100, 100, 250)); // رنگ آبی ملایم
    this->position = position;
    if (!font.loadFromFile("../Horrified_Assets/arial.ttf")) {
        // باید فونت arial را کنار برنامه داشته باشی
        throw std::runtime_error("Could not load font");
    }

    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(20);
    label.setFillColor(sf::Color::White);

    // مرکز چین کردن متن درون دکمه
    sf::FloatRect textBounds = label.getLocalBounds();
    label.setOrigin(textBounds.width / 2, textBounds.height / 2);
    label.setPosition(
        position.x + size.x / 2,
        position.y + size.y / 2 - 5  // تنظیم ظاهری برای ارتفاع
    );
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(label);
}

bool Button::isClicked(const sf::Event& event, const sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            return true;
        }
    }
    return false;
}

sf::Vector2f Button::getPosButton()
{
    return position;
}
