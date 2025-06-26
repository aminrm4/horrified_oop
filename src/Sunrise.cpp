#include "Sunrise.hpp"
#include <iostream>

void Sunrise::event(perk * p,hero* hero, monster *m,std::vector<std::vector<int>>& map,std::vector<location*>& loc , programm& a)
{
    
    m->set_loc(loc[7]);
    std::cout<<"Drakula moved to Crypt \n";
}
void Sunrise::monster_strike(int dice_attack,int move, vector<monster*> &monsters , vector<int>  &route , vector<location*>&loc , hero* h )
{
     for (int i = 0; i < monsters.size(); i++)
    {
        if(monsters[i]->get_freenzy_status())
            monster_card::monster_strike( dice_attack, move, monsters[i]  , route ,loc ,h );
    }
        for (int i = 0; i < monsters.size(); i++)
    {
        if(typeid(*monsters[i]).name() == typeid(invisible_man).name())
                monster_card::monster_strike(dice_attack , move , monsters[i] , route , loc , h);

    }
}