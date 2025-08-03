#include "On_the_move.hpp"
#include "programm.hpp"
void remove_villager(programm &, villager *);
void On_the_move::event(std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a)
{
    vector<int> route;
    a.next_frenzy();
    for (int i = 0; i < a.list_of_location.size(); i++)
    {
        for (auto vill : a.list_of_location.at(i)->get_villager_list())
        {
            route = (a.bfs(vill->get_currnet_location()->get_loc_relation(), vill->get_safe_location()->get_loc_relation()));
            if (route.empty())
            {
                continue;
            }
            else
            {
                cout << vill->get_name() << endl;
                cout << a.list_of_location.at(i)->get_loc_relation() << endl;
                remove_villager(a, vill);
                a.list_of_location[route[1]]->set_villager(vill);
                vill->set_current_location(a.list_of_location[route[1]]);
                cout << a.list_of_location.at(i)->get_loc_relation() << endl;
                if (vill->get_currnet_location() == vill->get_safe_location())
                {
                    remove_villager(a, vill);
                    delete vill;
                }
            }
        }
    }
    cout << "on the move monster card is done" << endl;
}
void On_the_move::monster_strike(programm &bug, vector<monster *> &monsters)
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if (monsters[i]->get_freenzy_status())
        {
            monster_card::_strike(dice_play, move_left, bug, monsters[i]);
        }
    }
}

void On_the_move::set_item(int item_count)
{
    this->item_count = item_count;
}

On_the_move::On_the_move(int dic, int my_item, int mover)
{
    dice_play = dic;
    item_count = my_item;
    move_left = mover;
    this->name_of_card = "OnTheMove";
}