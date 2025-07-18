#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

// Enum for load game states
enum class LoadGameState {
    Save1,
    Save2,
    Save3,
    Save4,
    Save5,
    Back, // New option for going back
    None // No selection
};

class LoadGameMenu {
public:
    LoadGameMenu(float width, float height, const sf::Font& font);
    void draw(sf::RenderWindow& window);
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    LoadGameState getSelectedState() const;
    bool isStateSelected() const;
    void resetSelection();
    LoadGameState run();
private:
    std::vector<sf::Text> saveItems;
    LoadGameState selectedState;
    int hoveredIndex;
    bool stateSelected;
    void updateHighlight();
};
