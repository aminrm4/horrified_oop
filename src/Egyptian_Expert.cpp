#include "Egyptian_Expert.hpp"
#include "programm.hpp"
using namespace std;
void Egyptian_Expert::event(perk * p,hero* hero, monster *m,std::vector<std::vector<int>>& map,std::vector<location*>& loc , programm& a)
{
    for (int i = 0; i < loc.size(); i++)
    {
        if(loc[i]->get_loc_relation() == 14)
            for (int j = 0; j < loc.size(); j++)
            {
                if(loc[j]->get_loc_relation() == 6)
                    loc[i]->set_villager(new villager("Prof.person" ,loc[j] ,loc[i] , a));
            }
            

    }
        cout << "Prof.person sommend in cave go and help him \n";
    
    
}
void Egyptian_Expert::monster_strike(int dice_attack,int move, vector<monster*>&  monsters , vector<int>  & route , vector<location*>&loc , hero* h )
{
    
    for (int i = 0; i < monsters.size(); i++)
    {
        if(typeid(*monsters[i]).name() == typeid(Drakula).name())
            monster_card::monster_strike( dice_attack, move, monsters[i]  , route ,loc ,h );
    }
    
    for (int i = 0; i < monsters.size(); i++)
    {
        if(monsters[i]->get_freenzy_status())
            monster_card::monster_strike( dice_attack, move, monsters[i]  , route ,loc ,h );
    }
}

