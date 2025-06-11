#pragma once
#include "monster_card.hpp"
#include "programm.hpp"
#include "monster.hpp"
int monster_card::get_item_count()
{
    return item_count;
}
void monster_card::monster_strike(int dice_attack,int move, monster* monsters , vector<int> route , vector<location*>&loc , hero* h )
{
        programm p;
        monsters->move_to_place( route, move ,loc);
        cout << "look a monster moved his place be careful \n";
        set<int> a = p.random_generator(1 , 36 , 1);
        set<int>::iterator it = a.begin();
        it++;
        if(*it == 1)  // ability
        {
            cout << "Oh no the monster want to use his ability a player \n";
            monsters->ability(route , loc, h);
        }
        if(*it == 2) // strike
        {
            cout << "Oh no the monster want to strike !!! \n";
            vector<villager*> v = monsters->get_loc()->get_villager_list();
            if(!v.empty())
            {
                cout << "Oh noooooo a villager died ";
                cout << "RIP villager \n";
                v.erase(v.begin());
                //monsters->get_loc()->villager_list;
            }
        }
        
}
