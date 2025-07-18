#include "Fortune_Teller.hpp"

void Fortune_Teller::event(std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a)
{

    a.list_of_location[18]->set_villager((new villager("maleva", loc[5], loc[18], a)));

    cout << "maleva sommend in camp go and help him \n";
}
void Fortune_Teller::monster_strike(programm &bug, vector<monster *> &monsters)
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if (monsters[i]->get_freenzy_status())
            monster_card::_strike(dice_play, move_left, bug, monsters[i]);
    }
}
void Fortune_Teller::set_item(int item_count)
{
    this->item_count = item_count;
}

Fortune_Teller::Fortune_Teller(int dic, int my_item, int mover)
{
    item_count = my_item;
    dice_play = dic;
    move_left = mover;
    this->name_of_card="Fortune_Teller";
}
