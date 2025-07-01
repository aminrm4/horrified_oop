#pragma once
#include "monster_card.hpp"
using namespace std;
class Hypnotic_Gaze : public monster_card
{
    public:
    void event(perk * p,hero* hero, monster *m,std::vector<std::vector<int>>& map,std::vector<location*>& loc  , programm&);
    void monster_strike(int dice_attack,int move, programm &,vector<monster*> & monsters , vector<int>  & route , vector<location*>&loc , hero* h );
    void set_item(int item_count);
    Hypnotic_Gaze( int dic,int my_item,int mover);
};