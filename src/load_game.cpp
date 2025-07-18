#include "load_game.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

LoadGameMenu::LoadGameMenu(float width, float height, const sf::Font& font)
    : selectedState(LoadGameState::None), hoveredIndex(-1), stateSelected(false)
{
    vector<string> labels = { "Save 1", "Save 2", "Save 3", "Save 4", "Save 5", "Back" };
    saveItems.resize(labels.size());
    float centerX = width / 2.f;
    // Y-positions for 5 buttons
    vector<float> yPositions = { 380.f, 520.f, 640.f, 760.f, 880.f };
    for (size_t i = 0; i < 5; ++i) {
        saveItems[i].setFont(font);
        saveItems[i].setString(labels[i]);
        saveItems[i].setCharacterSize(80); // Large, horror style
        saveItems[i].setFillColor(sf::Color(173, 216, 230));
        sf::FloatRect bounds = saveItems[i].getLocalBounds();
        saveItems[i].setOrigin(bounds.width / 2, bounds.height / 2);
        saveItems[i].setPosition(centerX, yPositions[i]);
    }
    // Back button: bottom right
    int backIdx = 5;
    saveItems[backIdx].setFont(font);
    saveItems[backIdx].setString(labels[backIdx]);
    saveItems[backIdx].setCharacterSize(60);
    saveItems[backIdx].setFillColor(sf::Color(173, 216, 230));
    sf::FloatRect backBounds = saveItems[backIdx].getLocalBounds();
    float marginX = 60.f;
    float marginY = 120.f; // Move up from the bottom
    saveItems[backIdx].setOrigin(backBounds.width, backBounds.height); // anchor bottom right
    saveItems[backIdx].setPosition(width - marginX, height - marginY);
    updateHighlight();
}

void LoadGameMenu::draw(sf::RenderWindow& window) {
    for (const auto& item : saveItems) {
        window.draw(item);
    }
}

void LoadGameMenu::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    hoveredIndex = -1;
    for (size_t i = 0; i < saveItems.size(); ++i) {
        if (saveItems[i].getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            hoveredIndex = static_cast<int>(i);
            break;
        }
    }
    updateHighlight();
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (hoveredIndex != -1) {
            selectedState = static_cast<LoadGameState>(hoveredIndex);
            stateSelected = true;
            updateHighlight();
        }
    }
}

LoadGameState LoadGameMenu::getSelectedState() const {
    return selectedState;
}

bool LoadGameMenu::isStateSelected() const {
    return stateSelected;
}

void LoadGameMenu::resetSelection() {
    stateSelected = false;
}

void LoadGameMenu::updateHighlight() {
    for (size_t i = 0; i < saveItems.size(); ++i) {
        if (static_cast<int>(i) == hoveredIndex) {
            saveItems[i].setFillColor(sf::Color(255, 0, 0)); // Red highlight for hovered
        } else if (stateSelected && static_cast<int>(i) == static_cast<int>(selectedState)) {
            saveItems[i].setFillColor(sf::Color(255, 0, 0)); // Red for selected
        } else {
            saveItems[i].setFillColor(sf::Color(173, 216, 230)); // Light blue
        }
    }
}

LoadGameState LoadGameMenu::run() {
    const unsigned int WIDTH = 1920, HEIGHT = 1080;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Load Game");
    window.setFramerateLimit(60);

    // Load background
    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("../Horrified_Assets/load.png")) {
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

    // Re-initialize save items with loaded font and new positions
    *this = LoadGameMenu(WIDTH, HEIGHT, font);

    sf::Music music;
    if (music.openFromFile("../sounds/load.mp3")) {
        music.setLoop(true);
        music.play();
    }

    bool showConfirm = false;
    bool confirmResult = false;
    LoadGameState result = LoadGameState::None;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (!showConfirm) {
                handleEvent(event, window);
            } else {
                // Handle confirmation dialog events
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    // Yes button
                    sf::FloatRect yesRect(WIDTH/2 - 200, HEIGHT/2 + 60, 150, 80);
                    // No button
                    sf::FloatRect noRect(WIDTH/2 + 50, HEIGHT/2 + 60, 150, 80);
                    if (yesRect.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        confirmResult = true;
                        showConfirm = false;
                    } else if (noRect.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        confirmResult = false;
                        showConfirm = false;
                        // Reset selection
                        stateSelected = false;
                        selectedState = LoadGameState::None;
                    }
                }
            }
        }
        window.clear();
        window.draw(bgSprite);
        draw(window);
        if (showConfirm) {
            // Draw confirmation dialog
            sf::RectangleShape dialogBox(sf::Vector2f(600, 300));
            dialogBox.setFillColor(sf::Color(30, 30, 30, 230));
            dialogBox.setOutlineColor(sf::Color::Red);
            dialogBox.setOutlineThickness(5);
            dialogBox.setOrigin(300, 150);
            dialogBox.setPosition(WIDTH/2, HEIGHT/2);
            window.draw(dialogBox);

            sf::Text confirmText;
            confirmText.setFont(font);
            confirmText.setString("Do you really want to go back?");
            confirmText.setCharacterSize(48);
            confirmText.setFillColor(sf::Color(255, 255, 255));
            sf::FloatRect textBounds = confirmText.getLocalBounds();
            confirmText.setOrigin(textBounds.width/2, textBounds.height/2);
            confirmText.setPosition(WIDTH/2, HEIGHT/2 - 40);
            window.draw(confirmText);

            // Yes button
            sf::RectangleShape yesBtn(sf::Vector2f(150, 80));
            yesBtn.setFillColor(sf::Color(100, 255, 100));
            yesBtn.setOrigin(75, 40);
            yesBtn.setPosition(WIDTH/2 - 125, HEIGHT/2 + 100);
            window.draw(yesBtn);
            sf::Text yesText;
            yesText.setFont(font);
            yesText.setString("Yes");
            yesText.setCharacterSize(40);
            yesText.setFillColor(sf::Color::Black);
            sf::FloatRect yesBounds = yesText.getLocalBounds();
            yesText.setOrigin(yesBounds.width/2, yesBounds.height/2);
            yesText.setPosition(WIDTH/2 - 125, HEIGHT/2 + 100);
            window.draw(yesText);

            // No button
            sf::RectangleShape noBtn(sf::Vector2f(150, 80));
            noBtn.setFillColor(sf::Color(255, 100, 100));
            noBtn.setOrigin(75, 40);
            noBtn.setPosition(WIDTH/2 + 125, HEIGHT/2 + 100);
            window.draw(noBtn);
            sf::Text noText;
            noText.setFont(font);
            noText.setString("No");
            noText.setCharacterSize(40);
            noText.setFillColor(sf::Color::Black);
            sf::FloatRect noBounds = noText.getLocalBounds();
            noText.setOrigin(noBounds.width/2, noBounds.height/2);
            noText.setPosition(WIDTH/2 + 125, HEIGHT/2 + 100);
            window.draw(noText);
        }
        window.display();

        // Only close and return if:
        // - Back is confirmed (Yes)
        // - A save is selected (not Back)
        if (!showConfirm && confirmResult) {
            if (music.getStatus() == sf::Music::Playing) music.stop();
            sf::sleep(sf::seconds(0.3f));
            window.close();
            return LoadGameState::Back;
        }
        if (!showConfirm && isStateSelected()) {
            if (selectedState == LoadGameState::Back) {
                showConfirm = true;
                continue;
            } else if (selectedState != LoadGameState::None) {
                // Save selected, close and return
                if (music.getStatus() == sf::Music::Playing) music.stop();
                sf::sleep(sf::seconds(0.3f));
                window.close();
                return selectedState;
            }
        }
    }
    return LoadGameState::None;
}
