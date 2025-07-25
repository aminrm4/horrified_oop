#pragma once
#include"hero.hpp"
class courier:public hero
{
public:
 void special_action(std::vector<std::vector<int>> &map,programm & bug,sf::RenderWindow & window);
    courier(int, location *, std::vector<perk *> &);

};