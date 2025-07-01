#include "On_the_move.hpp"
#include"programm.hpp"
void On_the_move::event(perk *p, hero *hero, monster *m, std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a)
{
    a.next_frenzy();

    for (size_t i = 0; i < loc.size(); i++)
    {
        if (loc[i]->get_villager_list().empty())
        {
            continue;
        }
        else
        {
            auto it = loc[i]->get_villager_list();
            for (size_t j = 0; j < it.size(); j++)
            {
                auto pa = a.bfs(it[j]->get_currnet_location()->get_loc_relation(), it[j]->get_safe_location()->get_loc_relation());

                it[j]->set_current_location(loc[pa[1]]);
            }
        }
    }

}
void On_the_move::monster_strike(int dice_attack, int move, programm & bug ,vector<monster *>&  monsters, vector<int> & route, vector<location *> &loc, hero *h)
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if (monsters[i]->get_freenzy_status())
            {
                monster_card::_strike(dice_attack, move,bug, monsters[i]);
            }
    
    }
}
void On_the_move::set_item(int item_count)
{
    this->item_count = item_count;
}
    On_the_move::On_the_move(int dic,int my_item,int mover)
    {
        dice_play=dic;
        item_count=my_item;
        move_left=mover;
    }
