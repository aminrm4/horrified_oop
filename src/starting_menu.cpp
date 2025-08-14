#include "starting_menu.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
using namespace std;


int Menu::run() {
    const unsigned int width = 1920, height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), "Horrified Menu");
    window.setFramerateLimit(60);

    sf::Texture bg_texture;
    bg_texture.loadFromFile("../Horrified_Assets/menu.png");
    sf::Sprite bg_sprite(bg_texture);
    bg_sprite.setScale(
        float(width) / bg_texture.getSize().x,
        float(height) / bg_texture.getSize().y
    );

    sf::Font font;
    font.loadFromFile("../Horrified_Assets/creep.ttf");

    sf::Music music;
    music.openFromFile("../sounds/background.mp3");
    music.setLoop(true);
    music.play();

    vector<string> labels = { "New Game", "Load Game", "How to Play", "Exit" };
    buttons.resize(labels.size());
    float center_x = width / 2.f;
    vector<float> y_positions = { 470.f, 600.f, 730.f, 860.f };
    for (size_t i = 0; i < labels.size(); ++i) {
        buttons[i].setFont(font);
        buttons[i].setString(labels[i]);
        buttons[i].setCharacterSize(90);
        buttons[i].setFillColor(sf::Color(173, 216, 230));
        sf::FloatRect local = buttons[i].getLocalBounds();
        buttons[i].setOrigin(local.width / 2, local.height / 2);
        buttons[i].setPosition(center_x, y_positions[i]);
    }

    hovered_index = -1;
    auto update_highlight = [&]() {
        for (size_t i = 0; i < buttons.size(); ++i) {
            if (static_cast<int>(i) == hovered_index) {
                buttons[i].setFillColor(sf::Color(255, 255, 102));
            } else {
                buttons[i].setFillColor(sf::Color(173, 216, 230));
            }
        }
    };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseMoved) {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                hovered_index = -1;
                for (size_t i = 0; i < buttons.size(); ++i) {
                    if (buttons[i].getGlobalBounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y))) {
                        hovered_index = static_cast<int>(i);
                        break;
                    }
                }
                update_highlight();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (hovered_index != -1) {
                    music.stop();
                    sf::sleep(sf::seconds(0.2f));
                    window.close();
                    return hovered_index; 
                }
            }
        }

        window.clear();
        window.draw(bg_sprite);
        for (const auto &t : buttons) {
            window.draw(t);
        }
        window.display();
    }

    return 3;
}
