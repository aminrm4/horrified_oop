#include "Thief.hpp"

void event(perk * p,hero* hero, monster *m,std::vector<std::vector<int>>& map,std::vector<location*>& loc , programm& a)
{
    int max_item = 0;
    for (int i = 0; i < loc.size(); i++)
    {
        int temp = loc[i]->get_item_list().size();
        max_item = max(max_item , temp);
    }

    for (int i = 0; i < loc.size(); i++)
    {
        if(max_item == loc[i]->get_item_list().size())
            {
                m->set_loc(loc[i]);
                loc[i]->delete_item();
            }
    }
    
    
}
void Thief::monster_strike(int dice_attack,int move, vector<monster*> &monsters , vector<int> &route , vector<location*>&loc , hero* h )
{
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
