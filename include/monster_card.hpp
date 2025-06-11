#pragma once
#include <item.hpp>
#include <vector>
#include "hero.hpp"
#include "villager.hpp"
#include "monster.hpp"
#include "perk.hpp"

class monster_card
{
    public:
    virtual void event(perk * ,hero* hero, monster ,std::vector<std::vector<int>>& map, villager *)=0;
    void monster_strike(int dice_attack,int move, monster* monsters , vector<int> route , vector<location*>&loc , hero* h );
    int get_item_count();
    virtual ~monster_card(){}
    protected:
    int item_count;

};
