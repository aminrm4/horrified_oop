#pragma once
#include "hero.hpp"
#include <vector>
class Mayor : public hero
{
    int action;
    std::vector<item*> item_have;
    std::vector<perk*> perk_have;

};
