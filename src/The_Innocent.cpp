#include "The_Innocent.hpp"

void The_Innocent::event(perk * p,hero* hero, monster *m,std::vector<std::vector<int>>& map,std::vector<location*>& loc , programm& a)
{
    loc[15]->set_villager(new villager("Maria" ,loc[18], loc[15], a ));
                    cout << "Maria sommend in barn go and help him \n";

}
void The_Innocent::monster_strike(int dice_attack,int move, vector<monster*> & monsters , vector<int> & route , vector<location*>&loc , hero* h )
{
            for (int i = 0; i < monsters.size(); i++)
    {
        if(monsters[i]->get_freenzy_status())
            monster_card::monster_strike( dice_attack, move, monsters[i]  , route ,loc ,h );
    }
     for (int i = 0; i < monsters.size(); i++)
    {
        if(typeid(*monsters[i]).name() == typeid(Drakula).name())
            monster_card::monster_strike( dice_attack, move, monsters[i]  , route ,loc ,h );
    }
            for (int i = 0; i < monsters.size(); i++)
    {
        if(typeid(*monsters[i]).name() == typeid(invisible_man).name())
                monster_card::monster_strike(dice_attack , move , monsters[i] , route , loc , h);

    }
}

