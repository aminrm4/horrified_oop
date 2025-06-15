#include "The_Delivery .hpp"

void The_Delivery::event(perk * p,hero* hero, monster *m,std::vector<std::vector<int>>& map,std::vector<location*>& loc , programm& a)
{
    loc[12]->set_villager(new villager("Chick & Wilbur" , loc[16] , loc[12] , a));
                cout << "Chick & Wilbur sommend in docks go and help him \n";

}
void The_Delivery::monster_strike(int dice_attack,int move, vector<monster*> & monsters , vector<int> & route , vector<location*>&loc , hero* h )
{
        for (int i = 0; i < monsters.size(); i++)
    {
        if(monsters[i]->get_freenzy_status())
            monster_card::monster_strike( dice_attack, move, monsters[i]  , route ,loc ,h );
    }
}
