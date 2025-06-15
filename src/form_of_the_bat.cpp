#include "form_of_the_bat.hpp"
using namespace std;

void form_of_the_bat::event(perk * p,hero* hero, monster *m,std::vector<std::vector<int>>& map,std::vector<location*>& loc , programm& a)
{
    m->set_loc(hero->get_loc());
    cout << "the form_of_the_bat monster card played and Drakula teleported to a player \n";
}

void form_of_the_bat::monster_strike(int dice_attack,int move, vector<monster*>& monsters , vector<int> & route , vector<location*>&loc , hero* h )
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if(typeid(*monsters[i]).name() == typeid(invisible_man).name())
                monster_card::monster_strike(dice_attack , move , monsters[i] , route , loc , h);

    }
    
}