#pragma once
#include"hero.hpp"
class scientist:public hero
{
public:
 void special_action(std::vector<std::vector<int>> &map,programm & bug,sf::RenderWindow & window);
    scientist(int, location *, std::vector<perk *> &);

};