#include "Drakula.hpp"
#include <stdexcept>
#include <iostream>
#include "hero.hpp"
#include "programm.hpp"
using namespace std;
void remove_hero(programm &obj, hero *m);

Drakula::Drakula(int coffin, bool is_freenzy, int freenzy_order, location *ptr)
{
    if (coffin < 0)
        throw logic_error("invalid coffin\n");
    if (ptr == NULL)
        throw logic_error("place Drakula in a valid spot\n");
    if (freenzy_order < 0)
        throw invalid_argument("invalid freenzy order\n");

    this->is_freenzy = is_freenzy;
    this->freenzy_order = freenzy_order;
    this->totla_hidden_item = coffin;
    this->loc = ptr;
    name_of_monster = "Drakula";
}
void Drakula::ability(std::vector<int> &route, programm &bug, vector<location *> &locations, hero *h)
{

    for (auto her : bug.hero_list)
    {
        if (her->get_action() == 0)
        {    
            her->get_loc()->get_villager_list().insert(her->get_loc()->get_villager_list().end(),her->get_villagers().begin(),her->get_villagers().end());
            her->get_villagers().clear();
            her->move(this->get_loc(),bug);
            cout << "Drakula used his DarkCharm Ability and teleported you to his location \n";
            return;
        }
    }
}
