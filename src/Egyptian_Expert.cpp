#include "Egyptian_Expert.hpp"
#include "programm.hpp"
#include "Drakula.hpp"
using namespace std;
void Egyptian_Expert::event(std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a)
{

    cout << "Prof.person sommend in cave go and help him \n";
    a.list_of_location[17]->set_villager((new villager("Prof.pearson", loc[6], loc[17], a)));
}
void Egyptian_Expert::monster_strike(programm &bug, vector<monster *> &monsters)
{

    for (int i = 0; i < monsters.size(); i++)
    {
        if (typeid(*monsters[i]).name() == typeid(Drakula).name())
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
void Egyptian_Expert::set_item(int item_count)
{
    this->item_count = item_count;
}
Egyptian_Expert::Egyptian_Expert(int dic, int my_item, int mover)
{
    dice_play = dic;
    item_count = my_item;
    move_left = mover;
    this->name_of_card="Egyptian_Expert";
}
