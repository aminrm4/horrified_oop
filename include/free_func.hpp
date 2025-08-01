#pragma once
#include <SFML/Graphics.hpp>
#include "programm.hpp"
int showLocationTextBox(sf::RenderWindow &window, programm &bug, hero &herr);
void showCenteredTextBox(sf::RenderWindow &window, const std::string &text);
void showAssetInBox(sf::RenderWindow &window, const std::string &directory, const std::string &assetName);
std::string showTextInputBox(sf::RenderWindow &window, const std::string &prompt);
int extractNumber(const std::string &pathStr);
std::string showHerovillagerBox(sf::RenderWindow &window, int loc_selec, programm &bug);
std::string showHeroPerksBox(sf::RenderWindow &window, hero *heroPtr);
std::string showHeroitemBox(sf::RenderWindow &window, int loc_selec, programm &bug);
std::string show_hero_on_location(sf::RenderWindow & window,programm &bug);
int show_all_location(sf::RenderWindow &window,programm & bug);
int show_monster_location(sf::RenderWindow &window, programm &bug, monster* monn);
void playSound(std::string SoundDir);
std::string show_hero_item_have(sf::RenderWindow &window, hero *heroPtr);
std::string show_monster_asset(sf::RenderWindow &window, const std::string &monster_folder_path);

