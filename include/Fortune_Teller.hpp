#pragma once
#include "monster_card.hpp"

class Fortune_Teller : public monster_card
{
    public:
    void event(perk * ,hero* hero, monster ,std::vector<std::vector<int>>& map, villager *);
    void monster_strike(int dice_attack,int move,monster *);
};