#pragma once
#include <SFML/Graphics.hpp>
#include "programm.hpp"
int showLocationTextBox(sf::RenderWindow &window, programm &bug, hero &herr);
void showCenteredTextBox(sf::RenderWindow &window, const std::string &text);
int showAssetSelectionBox(sf::RenderWindow &window, const std::string &directory);
void showAssetInBox(sf::RenderWindow &window, const std::string &directory, const std::string &assetName);
std::string showTextInputBox(sf::RenderWindow &window, const std::string &prompt);
int extractNumber(const std::string &pathStr);
std::string showHerovillagerBox(sf::RenderWindow &window, int loc_selec, programm &bug);
std::string showHeroPerksBox(sf::RenderWindow &window, hero *heroPtr);
std::string showHeroitemBox(sf::RenderWindow &window, int loc_selec, programm &bug);
