#pragma once
#include "monster_card.hpp"
class programm;
using namespace std;
class Sunrise : public monster_card
{
    int item_count = 0;
    public:
    void event(perk * p,hero* hero, monster *m,std::vector<std::vector<int>>& map,std::vector<location*>& loc , programm& a);
    void monster_strike(int dice_attack,int move,programm &, vector<monster*> &monsters , vector<int>  &route , vector<location*>&loc , hero* h );
    void set_item(int item_count);
    int get_item();
};