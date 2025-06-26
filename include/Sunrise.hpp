#pragma once
#include "monster_card.hpp"
using namespace std;
class Sunrise : public monster_card
{
    public:
    void event(perk * ,hero* hero, monster ,std::vector<std::vector<int>>& map, villager *);
    void monster_strike(int dice_attack,int move,std::vector<monster *>&  monsters , vector<int> & route , vector<location*>&loc);
};