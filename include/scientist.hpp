#pragma once
#include"hero.hpp"
class scientist:public hero
{

 void special_action(std::vector<std::vector<int>> &map,programm & bug);
    scientist(int, location *, std::vector<perk *> &);

};