#include "Former_Employer.hpp"
using namespace std;

void Former_Employer::event(perk *p, hero *hero, monster *m, std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a)
{

    a.list_of_location[4]->set_villager((new villager("Dr.cranly", loc[14], loc[4], a)));

    cout << "Dr.cranly sommend in labratory go and help him \n";
}
void Former_Employer::monster_strike(int dice_attack, int move, programm &bug, vector<monster *> &monsters, vector<int> &route, vector<location *> &loc, hero *h)
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if (typeid(*monsters[i]).name() == typeid(invisible_man).name())
            monster_card::monster_strike(dice_attack, move, bug, monsters[i], route, loc, h);
    }
    for (int i = 0; i < monsters.size(); i++)
    {
        if (monsters[i]->get_freenzy_status())
            monster_card::monster_strike(dice_attack, move, bug, monsters[i], route, loc, h);
    }
}
void Former_Employer::set_item(int item_count)
{
    this->item_count = item_count;
}
int Former_Employer::get_item()
{
    return item_count;
}