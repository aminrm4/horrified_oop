#pragma once
#include <SFML/Graphics.hpp>
int showLocationTextBox(sf::RenderWindow& window);
void showCenteredTextBox(sf::RenderWindow& window, const std::string& text);
int showAssetSelectionBox(sf::RenderWindow& window, const std::string& directory);