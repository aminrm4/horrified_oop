#include "Thief.hpp"
#include "Invisible_man.hpp"
#include "map1.hpp"

void remove_monster(programm &obj, monster *m);
void Thief::event(std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a)
{
    int max_item = 0;
    for (int i = 0; i < loc.size(); i++)
    {
        int temp = a.list_of_location[i]->get_item_list().size();
        max_item = max(max_item, temp);
    }

    for (int i = 0; i < loc.size(); i++)
    {
        if (max_item == a.list_of_location[i]->get_item_list().size())
        {

            for (auto mons : a.monster_list)
            {
                if (typeid(*mons).name() == typeid(invisible_man).name())
                {
                    remove_monster(a, mons);
                    mons->set_loc(a.list_of_location[i]);
                    a.list_of_location[i]->set_monster_list(mons);
                    a.list_of_location[i]->delete_item();
                    cout << "Invisible man  teleported to" << (a.list_of_location[i]->get_loc_relation()) << " and  destoyed all the items" << endl;
                }
            }
        }
    }
}
void Thief::monster_strike(programm &bug, vector<monster *> &monsters)
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

    for (int i = 0; i < monsters.size() &&!check; i++)
    {
        if (typeid(*monsters[i]).name() == typeid(Drakula).name())
            monster_card::_strike(dice_play, move_left, bug, monsters[i]);
    }
}
Thief::Thief(int dic, int my_item, int mover)
{
    dice_play = dic;
    item_count = my_item;
    move_left = mover;
    this->name_of_card="Thief";
}
