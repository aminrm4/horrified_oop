#pragma once
#include "hero.hpp"
#include <vector>
#include<SFML/Graphics.hpp>
class Mayor : public hero
{
public:
   void special_action(std::vector<std::vector<int>> &map,programm & bug,sf::RenderWindow & window);
   Mayor(int, location *, std::vector<perk *> &);
};
