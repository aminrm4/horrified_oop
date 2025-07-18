#pragma once
#include "hero.hpp"

class Archaeologist : public hero
{

public:
    void special_action(std::vector<std::vector<int>> &map,programm & bug);
    Archaeologist(int, location *, std::vector<perk *> &);
};