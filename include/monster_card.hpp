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
    virtual void event(std::vector<std::vector<int>>& map,std::vector<location*>& loc , programm& a) =0;
    void _strike(int dice_attack,int move,  programm & bug,monster* monsters);
    virtual void monster_strike(programm &bug, vector<monster *> &monsters) = 0;
    void item_handler(programm &help_object);
      int get_item_count();
      int get_dice_play();
      int get_move_count();
    virtual ~monster_card(){}
    protected:
    int item_count;
    int dice_play;
    int move_left;



};
