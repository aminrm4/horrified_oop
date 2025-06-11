#pragma once
#include "monster_card.hpp"
using namespace std;
class The_Innocent : public monster_card
{
    public:
    void event(perk * ,hero* hero, monster ,std::vector<std::vector<int>>& map, villager *);
    void monster_strike(int dice_attack,int move, vector<monster*> monsters , vector<int> route , vector<location*>&loc , hero* h );
};