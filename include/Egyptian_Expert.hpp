#pragma once
#include "monster_card.hpp"
#include "programm.hpp"
#include <vector>
class Egyptian_Expert
{
    public:
    void event(perk * ,hero* hero, monster ,std::vector<std::vector<int>>& map,std::vector<location*>& loc);
    void monster_strike(int dice_attack,int move,std::vector<monster *> monsters , vector<int> route , vector<location*>&loc);
};

