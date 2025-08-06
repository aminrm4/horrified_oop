#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class LoadGameMenu {
public:
    LoadGameMenu();
    std::string run();
private:
    std::string clickedButton;
    sf::RenderWindow window;
};
