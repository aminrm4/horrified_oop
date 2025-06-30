#include "Hurried_Assistant.hpp"

void Hurried_Assistant::event(perk *p, hero *hero, monster *m, std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a)
{

    a.list_of_location[11]->set_villager((new villager("Fritz", loc[3], loc[11], a)));

    cout << "Fritz sommend  go and help him \n";
}
void Hurried_Assistant::monster_strike(int dice_attack, int move, programm &bug, vector<monster *> &monsters, vector<int> &route, vector<location *> &loc, hero *h)
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if (typeid(*monsters[i]).name() == typeid(Drakula).name())
            monster_card::monster_strike(dice_attack, move, bug, monsters[i], route, loc, h);
    }
}
void Hurried_Assistant::set_item(int item_count)
{
    this->item_count = item_count;
}
int Hurried_Assistant::get_item()
{
    return item_count;
}