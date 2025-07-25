#include "On_the_move.hpp"
#include "programm.hpp"
void remove_villager(programm &, villager *);
void On_the_move::event(std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a)
{
    cout << "on the move monster card is done" << endl;
    vector<int> route;
    a.next_frenzy();
    for (int i = 0; i < a.list_of_location.size(); i++)
    {
        for (auto vill : a.list_of_location.at(i)->get_villager_list())
        {
            route = (a.bfs(vill->get_currnet_location()->get_loc_relation(), vill->get_safe_location()->get_loc_relation()));
            if (route.empty())
            {
                throw invalid_argument("no villager exist to move in their safe location\n");
            }
            else
            {
                remove_villager(a, vill);
                a.list_of_location[route[1]]->set_villager(vill);
                vill->set_current_location(a.list_of_location[route[1]]);
            }
        }
    }
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
    this->name_of_card="On_the_move";
}