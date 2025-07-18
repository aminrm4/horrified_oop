#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

// Enum for menu states
enum class MenuState {
    NewGame,
    LoadGame,
    HowToPlay,
    Exit,
    Count // Helper for number of states
};

class Menu {
public:
    Menu(float width, float height, const sf::Font& font);
    void draw(sf::RenderWindow& window);
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    MenuState getSelectedState() const;
    bool isStateSelected() const;
    void resetSelection();
    MenuState run(); // Add this declaration
private:
    std::vector<sf::Text> menuItems;
    MenuState selectedState;
    int hoveredIndex;
    bool stateSelected;
    void updateHighlight();
};
