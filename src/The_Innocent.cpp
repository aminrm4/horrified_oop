#include "The_Innocent.hpp"

void The_Innocent::event(std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a)
{

    a.list_of_location[15]->set_villager((new villager("Maria", loc[18], loc[15], a)));
    cout << "Maria sommend in barn go and help him \n";
}
void The_Innocent::monster_strike(programm &bug, vector<monster *> &monsters)
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if (monsters[i]->get_freenzy_status())
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
        if (typeid(*monsters[i]).name() == typeid(Drakula).name())
            monster_card::_strike(dice_play, move_left, bug, monsters[i]);
    }
    for (auto mon : monsters)
    {
        if (mon->get_did_attack())
        {
            check = true;
        }
    }
    for (int i = 0; i < monsters.size() && !check; i++)
    {
        if (typeid(*monsters[i]).name() == typeid(invisible_man).name())
            monster_card::_strike(dice_play, move_left, bug, monsters[i]);
    }
}
void The_Innocent::set_item(int item_count)
{
    this->item_count = item_count;
}
The_Innocent::The_Innocent(int dic, int my_item, int mover)
{
    dice_play = dic;
    item_count = my_item;
    move_left = mover;
    this->name_of_card="The_innocent";
}
