#include "Egyptian_Expert.hpp"

using namespace std;
void Egyptian_Expert::event(perk * p,hero* hero, monster ,std::vector<std::vector<int>>& map,std::vector<location*>& loc)
{
    for (int i = 0; i < loc.size(); i++)
    {
        if(loc[i]->get_loc_relation() == 14)
            for (int j = 0; j < loc.size(); j++)
            {
                if(loc[j]->get_loc_relation() == 6)
                    loc[i]->set_villager(new villager("Prof.person" ,loc[j] ,loc[i]));
            }
            

    }
    
    
}
void Egyptian_Expert::monster_strike(int dice_attack,int move,monster *)
{
    
}
