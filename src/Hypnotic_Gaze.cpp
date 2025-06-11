#include "Hypnotic_Gaze.hpp"

void Hypnotic_Gaze::event(perk * p,hero* hero, monster *m,std::vector<std::vector<int>>& map,std::vector<location*>& loc)
{
    // fix here
}
void Hypnotic_Gaze::monster_strike(int dice_attack,int move, vector<monster*> monsters , vector<int> route , vector<location*>&loc , hero* h )
{
        for (int i = 0; i < monsters.size(); i++)
    {
        if(typeid(*monsters[i]).name() == typeid(invisible_man).name())
                monster_card::monster_strike(dice_attack , move , monsters[i] , route , loc , h);

    }
}