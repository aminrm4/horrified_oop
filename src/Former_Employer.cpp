#include "Former_Employer.hpp"
using namespace std;

void Former_Employer::event(std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a)
{

    a.list_of_location[4]->set_villager((new villager("DrCranly", loc[14], loc[4], a)));

    cout << "Dr.cranly sommend in labratory go and help him \n";
}
void Former_Employer::monster_strike(programm &bug, vector<monster *> &monsters)
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
void Former_Employer::set_item(int item_count)
{
    this->item_count = item_count;
}
Former_Employer::Former_Employer(int dic, int my_item, int mover)
{
    item_count = my_item;
    dice_play = dic;
    move_left = mover;
    this->name_of_card="Former_Employer";
}
