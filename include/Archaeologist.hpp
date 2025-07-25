#pragma once
#include "hero.hpp"
#include<SFML/Graphics.hpp>

class Archaeologist : public hero
{

public:
    void special_action(std::vector<std::vector<int>> &map,programm & bug,sf::RenderWindow & window);
    Archaeologist(int, location *, std::vector<perk *> &);
};