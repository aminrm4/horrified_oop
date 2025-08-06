#include "load_game.hpp"
#include <vector>
#include <SFML/Audio.hpp>

LoadGameMenu::LoadGameMenu() : clickedButton(""), window(sf::VideoMode(800, 600), "Load Game") {
    window.setFramerateLimit(60);
}

std::string LoadGameMenu::run() {
    const unsigned int WIDTH = 800, HEIGHT = 600;

    // Load background (optional, fallback to color if not found)
    sf::Texture bgTexture;
    sf::Sprite bgSprite;
    bool hasBg = false;
    if (bgTexture.loadFromFile("../Horrified_Assets/load.png")) {
        bgSprite.setTexture(bgTexture);
        bgSprite.setScale(
            float(WIDTH) / bgTexture.getSize().x,
            float(HEIGHT) / bgTexture.getSize().y
        );
        hasBg = true;
    }

    // Load font (no error or fallback)
    sf::Font font;
    font.loadFromFile("../Horrified_Assets/creep.ttf");

    // Play background music (no error)
    sf::Music music;
    music.openFromFile("../sounds/load.mp3");
    music.setLoop(true);
    music.play();

    // Button labels (as text only)
    std::vector<std::string> labels = {"Save 1", "Save 2", "Save 3", "Save 4", "Save 5", "Back"};
    std::vector<sf::Text> texts(labels.size());
    float startY = 180, gap = 60;
    for (size_t i = 0; i < labels.size(); ++i) {
        texts[i].setFont(font);
        texts[i].setString(labels[i]);
        texts[i].setCharacterSize(36);
        texts[i].setFillColor(sf::Color::White);
        sf::FloatRect textRect = texts[i].getLocalBounds();
        texts[i].setOrigin(textRect.width / 2, textRect.height / 2);
        texts[i].setPosition(WIDTH / 2, startY + i * gap);
    }

    clickedButton = "";
    while (window.isOpen()) {
        sf::Event event;
        sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
        sf::Vector2f mousePos = window.mapPixelToCoords(mousePixel);
        int hoveredIndex = -1;
        for (size_t i = 0; i < texts.size(); ++i) {
            sf::FloatRect bounds = texts[i].getGlobalBounds();
            float margin = 10.f;
            bounds.left -= margin;
            bounds.top -= margin;
            bounds.width += 2 * margin;
            bounds.height += 2 * margin;
            if (bounds.contains(mousePos)) {
                hoveredIndex = static_cast<int>(i);
                texts[i].setFillColor(sf::Color::Yellow);
            } else {
                texts[i].setFillColor(sf::Color::White);
            }
        }
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                if (music.getStatus() == sf::Music::Playing) music.stop();
                return "";
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                for (size_t i = 0; i < texts.size(); ++i) {
                    sf::FloatRect bounds = texts[i].getGlobalBounds();
                    float margin = 10.f;
                    bounds.left -= margin;
                    bounds.top -= margin;
                    bounds.width += 2 * margin;
                    bounds.height += 2 * margin;
                    if (bounds.contains(mousePos)) {
                        clickedButton = labels[i];
                        if (music.getStatus() == sf::Music::Playing) music.stop();
                        window.close();
                        return clickedButton;
                    }
                }
            }
        }
        window.clear(sf::Color(30, 30, 30));
        if (hasBg) window.draw(bgSprite);
        for (size_t i = 0; i < texts.size(); ++i) {
            window.draw(texts[i]);
        }
        window.display();
    }
    if (music.getStatus() == sf::Music::Playing) music.stop();
    return "";
}
