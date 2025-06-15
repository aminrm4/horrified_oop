#pragma once
#include "monster_card.hpp"
using namespace std;
class Thief : public monster_card
{
    public:
    void event(perk * p,hero* hero, monster *m,std::vector<std::vector<int>>& map,std::vector<location*>& loc);
    void monster_strike(int dice_attack,int move, vector<monster*> & monsters , vector<int>  & route , vector<location*>&loc , hero* h );
};