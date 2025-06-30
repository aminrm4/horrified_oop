#include "Fortune_Teller.hpp"

void Fortune_Teller::event(perk *p, hero *hero, monster *m, std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a)
{

    a.list_of_location[18]->set_villager((new villager("maleva", loc[5], loc[18], a)));

    cout << "maleva sommend in docks go and help him \n";
}
void Fortune_Teller::monster_strike(int dice_attack, int move, programm &bug, vector<monster *> &monsters, vector<int> &route, vector<location *> &loc, hero *h)
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if (monsters[i]->get_freenzy_status())
            monster_card::monster_strike(dice_attack, move, bug, monsters[i], route, loc, h);
    }
}
void Fortune_Teller::set_item(int item_count)
{
    this->item_count = item_count;
}
int Fortune_Teller::get_item()
{
    return item_count;
}