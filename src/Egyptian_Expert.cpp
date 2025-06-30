#include "Egyptian_Expert.hpp"
#include "programm.hpp"
#include "Drakula.hpp"
using namespace std;
void Egyptian_Expert::event(perk *p, hero *hero, monster *m, std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a)
{

    cout << "Prof.person sommend in cave go and help him \n";
    a.list_of_location[17]->set_villager((new villager("Prof.pearson", loc[6], loc[17], a)));
}
void Egyptian_Expert::monster_strike(int dice_attack, int move, programm &bug, vector<monster *> &monsters, vector<int> &route, vector<location *> &loc, hero *h)
{

    for (int i = 0; i < monsters.size(); i++)
    {
        if (typeid(*monsters[i]).name() == typeid(Drakula).name())
            monster_card::monster_strike(dice_attack, move, bug, monsters[i], route, loc, h);
    }

    for (int i = 0; i < monsters.size(); i++)
    {
        if (monsters[i]->get_freenzy_status())
            monster_card::monster_strike(dice_attack, move, bug, monsters[i], route, loc, h);
    }
}
void Egyptian_Expert::set_item(int item_count)
{
    this->item_count = item_count;
}
int Egyptian_Expert::get_item()
{
    return item_count;
}