#include "Sunrise.hpp"
#include <iostream>
#include "Drakula.hpp"
void remove_monster(programm &obj, monster *m);

void Sunrise::event(std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a)
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

void Sunrise::monster_strike(programm &bug, vector<monster *> &monsters)
{

    for (int i = 0; i < monsters.size(); i++)
    {
        if (typeid(*monsters[i]).name() == typeid(invisible_man).name())
            monster_card::_strike(dice_play, move_left, bug, monsters[i]);
    }
    bool check = false;
    for (auto mon : monsters)
    {
        if (mon->get_did_attack())
        {
            check = true;
        }
    }

    for (int i = 0; i < monsters.size() && !check; i++)
    {
        if (monsters[i]->get_freenzy_status())
            monster_card::_strike(dice_play, move_left, bug, monsters[i]);
    }
}
void Sunrise::set_item(int item_count)
{
    this->item_count = item_count;
}
Sunrise::Sunrise(int dic, int my_item, int mover)
{
    item_count = my_item;
    dice_play = dic;
    move_left = mover;
    this->name_of_card="Sunrise";
}
