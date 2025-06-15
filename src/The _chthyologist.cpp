#include "The_chthyologist.hpp"

void The_chthyologist::event(perk * p,hero* hero, monster *m,std::vector<std::vector<int>>& map,std::vector<location*>& loc , programm& a)
{
    loc[3]->set_villager(new villager("Dr.Reed" , loc[18] , loc[3] , a));
            cout << "Dr.Reed sommend in institute go and help him \n";

}
void The_chthyologist::monster_strike(int dice_attack,int move, vector<monster*>&  monsters , vector<int>&  route , vector<location*>&loc , hero* h )
{
        for (int i = 0; i < monsters.size(); i++)
    {
        if(monsters[i]->get_freenzy_status())
            monster_card::monster_strike( dice_attack, move, monsters[i]  , route ,loc ,h );
    }
}
