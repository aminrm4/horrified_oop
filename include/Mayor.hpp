#pragma once
#include "hero.hpp"
#include <vector>
class Mayor : public hero
{
public:
   void special_action(std::vector<std::vector<int>> &map,programm & bug);
   Mayor(int, location *, std::vector<perk *> &);
};
