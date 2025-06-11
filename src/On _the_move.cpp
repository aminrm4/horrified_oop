#include "On _the_move.hpp"

void On_the_move::event(perk * p,hero* hero, monster *m,std::vector<std::vector<int>>& map,std::vector<location*>& loc , programm& a)
{

}
void On_the_move::monster_strike(int dice_attack,int move, vector<monster*> monsters , vector<int> route , vector<location*>&loc , hero* h )
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if(monsters[i]->get_freenzy_status())
            monster_card::monster_strike( dice_attack, move, monsters[i]  , route ,loc ,h );
    }
}
