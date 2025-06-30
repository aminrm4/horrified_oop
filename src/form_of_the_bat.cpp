#include "form_of_the_bat.hpp"
#include "Drakula.hpp"
using namespace std;
void remove_monster(programm &obj, monster *m);

void form_of_the_bat::event(perk *p, hero *hero, monster *m, std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a)
{

    for (auto mo : a.monster_list)
    {
        if (typeid(*mo).name() == typeid(Drakula).name())
        {
            for (auto her : a.hero_list)
            {
                if (her->get_action() == 0)
                {
                    remove_monster(a, mo);
                    mo->set_loc(her->get_loc());
                    her->get_loc()->set_monster_list(mo);
                    cout << "the form_of_the_bat monster card played and Drakula teleported to a player \n";
                    return;
                }
            }
        }
    }
}

void form_of_the_bat::monster_strike(int dice_attack, int move, programm &bug, vector<monster *> &monsters, vector<int> &route, vector<location *> &loc, hero *h)
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if (typeid(*monsters[i]).name() == typeid(invisible_man).name())
            monster_card::_strike(dice_attack, move, bug, monsters[i]);
    }
}
void form_of_the_bat::set_item(int item_count)
{
    this->item_count = item_count;
}
int form_of_the_bat::get_item()
{
    return item_count;
}