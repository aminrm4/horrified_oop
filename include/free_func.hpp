#pragma once
#include <SFML/Graphics.hpp>
int showLocationTextBox(sf::RenderWindow& window);
void showCenteredTextBox(sf::RenderWindow& window, const std::string& text);
int showAssetSelectionBox(sf::RenderWindow& window, const std::string& directory);
void showAssetInBox(sf::RenderWindow& window, const std::string& directory, const std::string& assetName);