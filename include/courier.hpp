#pragma once
#include"hero.hpp"
class courier:public hero
{

 void special_action(std::vector<std::vector<int>> &map,programm & bug);
    courier(int, location *, std::vector<perk *> &);

};