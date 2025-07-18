#include "Button2.hpp"

Button2::Button2(const sf::Vector2f& size, const sf::Vector2f& position , const std::string& Textuer_dir)
{
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Transparent);
    this->position = position;
    if (!texture.loadFromFile(Textuer_dir)) {
        
        throw std::runtime_error("Could not load texture of Button 2");
    }

   this->sprite.setTexture(texture);
   sprite.setScale({size.x / texture.getSize().x , size.y / texture.getSize().y });


    sf::FloatRect textBounds = sprite.getLocalBounds();
    sprite.setOrigin(textBounds.width / 2, textBounds.height / 2);
    sprite.setPosition(
        position.x + size.x / 2,
        position.y + size.y / 2  
    );
}

void Button2::draw(sf::RenderWindow& window) {
    if(this->selected)
    {
        shape.setOutlineThickness(5);
        shape.setOutlineColor(sf::Color::Red);
    }
    else
    shape.setOutlineThickness(0);

    window.draw(shape);
    window.draw(sprite);
}

bool Button2::isClicked(const sf::Event& event, const sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            return true;
        }
    }
    return false;
}

sf::Vector2f Button2::getPosButton()
{
    return position;
}
bool Button2::get_status()
{
    return this->selected;
}
void Button2::set_status(bool stat)
{
    this->selected = stat;
}
void Button2::set_pos(const sf::Vector2f& pos)
{
    this->position = pos;
}