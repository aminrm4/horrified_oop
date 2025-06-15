#include "On _the_move.hpp"
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
void On_the_move::monster_strike(int dice_attack, int move, vector<monster *>&  monsters, vector<int> & route, vector<location *> &loc, hero *h)
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if (monsters[i]->get_freenzy_status())
    
            monster_card::monster_strike(dice_attack, move, monsters[i], route, loc, h);
    }
}
