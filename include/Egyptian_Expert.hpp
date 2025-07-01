#pragma once
#include "monster_card.hpp"
#include "programm.hpp"
#include <vector>
class Egyptian_Expert : public monster_card
{
    
    public:
    void event(perk * ,hero* hero, monster *,std::vector<std::vector<int>>& map,std::vector<location*>& loc , programm&) ;
    void monster_strike(int dice_attack,int move,programm &,vector< monster *>  & monsters , vector<int>  & route , vector<location*>&loc , hero* h) ;
    void set_item(int item_count);
    Egyptian_Expert(int dic,int my_item,int mover);
};

