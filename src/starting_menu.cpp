#include "starting_menu.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

Menu::Menu(float width, float height, const sf::Font& font)
    : selectedState(MenuState::NewGame), hoveredIndex(-1), stateSelected(false)
{
    vector<string> labels = { "New Game", "Load Game", "How to Play", "Exit" };
    menuItems.resize(labels.size());
    float centerX = width / 2.f;
    // Adjust these y-positions to match the new menu.png image
    vector<float> yPositions = { 470.f, 600.f, 730.f, 860.f };
    for (size_t i = 0; i < labels.size(); ++i) {
        menuItems[i].setFont(font);
        menuItems[i].setString(labels[i]);
        menuItems[i].setCharacterSize(90); // Large, horror style
        menuItems[i].setFillColor(sf::Color(173, 216, 230));
        sf::FloatRect bounds = menuItems[i].getLocalBounds();
        menuItems[i].setOrigin(bounds.width / 2, bounds.height / 2);
        menuItems[i].setPosition(centerX, yPositions[i]);
    }
    updateHighlight();
}

void Menu::draw(sf::RenderWindow& window) {
    for (const auto& item : menuItems) {
        window.draw(item);
    }
}

void Menu::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    hoveredIndex = -1;
    for (size_t i = 0; i < menuItems.size(); ++i) {
        if (menuItems[i].getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            hoveredIndex = static_cast<int>(i);
            break;
        }
    }
    updateHighlight();
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (hoveredIndex != -1) {
            selectedState = static_cast<MenuState>(hoveredIndex);
            stateSelected = true;
            updateHighlight();
        }
    }
}

MenuState Menu::getSelectedState() const {
    return selectedState;
}

bool Menu::isStateSelected() const {
    return stateSelected;
}

void Menu::resetSelection() {
    stateSelected = false;
}

void Menu::updateHighlight() {
    for (size_t i = 0; i < menuItems.size(); ++i) {
        if (static_cast<int>(i) == hoveredIndex) {
            menuItems[i].setFillColor(sf::Color(255, 255, 102)); // Yellow highlight
        } else if (stateSelected && static_cast<int>(i) == static_cast<int>(selectedState)) {
            menuItems[i].setFillColor(sf::Color(255, 140, 0)); // Orange for selected
        } else {
            menuItems[i].setFillColor(sf::Color(173, 216, 230)); // Light blue
        }
    }
}

MenuState Menu::run() {
    const unsigned int WIDTH = 1920, HEIGHT = 1080;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Horrified Menu");
    window.setFramerateLimit(60);

    // Load new background
    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("../Horrified_Assets/menu.png")) {
        throw runtime_error("Could not load background image");
    }
    sf::Sprite bgSprite(bgTexture);
    bgSprite.setScale(
        float(WIDTH) / bgTexture.getSize().x,
        float(HEIGHT) / bgTexture.getSize().y
    );

    // Load creep font
    sf::Font font;
    if (!font.loadFromFile("../Horrified_Assets/creep.ttf")) {
        throw runtime_error("Could not load creep font");
    }

    // Re-initialize menu items with loaded font and new positions
    *this = Menu(WIDTH, HEIGHT, font);

    // Load and play background music
    sf::Music music;
    if (!music.openFromFile("../sounds/background.mp3")) {
        throw runtime_error("Could not load menu music");
    }
    music.setLoop(true);
    music.play();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            handleEvent(event, window);
        }
        window.clear();
        window.draw(bgSprite);
        draw(window);
        window.display();
        if (isStateSelected()) {
            music.stop();
            sf::sleep(sf::seconds(0.3f));
            window.close();
        }
    }
    return getSelectedState();
}
