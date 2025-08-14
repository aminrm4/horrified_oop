#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Menu {
public:
    int run();
private:
    std::vector<sf::Text> buttons;
    int hovered_index = -1;
};
