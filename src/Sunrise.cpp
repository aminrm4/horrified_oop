#include "Sunrise.hpp"
#include <iostream>
#include "Drakula.hpp"
void remove_monster(programm &obj, monster *m);

void Sunrise::event(perk *p, hero *hero, monster *m, std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a)
{

    for (auto mo : a.monster_list)
    {
        if (typeid(*mo).name() == typeid(Drakula).name())
        {
            remove_monster(a, mo);
            mo->set_loc(a.list_of_location[7]);
            a.list_of_location[7]->set_monster_list(mo);
            std::cout << "Drakula moved to Crypt \n";
             return;
        }
    }
}


void Sunrise::monster_strike(int dice_attack, int move, programm &bug, vector<monster *> &monsters, vector<int> &route, vector<location *> &loc, hero *h)
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if (monsters[i]->get_freenzy_status())
            monster_card::_strike(dice_attack, move, bug, monsters[i]);
    }
    for (int i = 0; i < monsters.size(); i++)
    {
        if (typeid(*monsters[i]).name() == typeid(invisible_man).name())
            monster_card::_strike(dice_attack, move, bug, monsters[i]);
    }
}
void Sunrise::set_item(int item_count)
{
    this->item_count = item_count;
}
int Sunrise::get_item()
{
    return item_count;
}