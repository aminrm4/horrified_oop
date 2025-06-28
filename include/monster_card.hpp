#pragma once
#include <item.hpp>
#include <vector>
#include "hero.hpp"
#include "villager.hpp"
#include "monster.hpp"
#include "perk.hpp"
#include "monster_card.hpp"
#include"programm.hpp"
class programm;

class monster_card
{
    public:
    virtual void event(perk * p,hero* hero, monster *m,std::vector<std::vector<int>>& map,std::vector<location*>& loc , programm& a) =0;
    void monster_strike(int dice_attack,int move,programm & , monster* monsters , std::vector<int> & route , std::vector<location*>&loc , hero* h );//logic error maybe
    int get_item_count();
    virtual ~monster_card(){}
    protected:
    int item_count;

};
