#include "Hypnotic_Gaze.hpp"
using namespace std;

void Hypnotic_Gaze::event(perk *p, hero *hero, monster *m, std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a)
{
    vector<int> hero_places;
    vector<villager *> option;
    vector<villager *> option1;
    bool find = false;
    int mon_place = m->get_loc()->get_loc_relation();
    for (size_t i = mon_place - 1; i <= 0; i--)
    {
        if (loc[i]->get_villager_list().empty())
        {
            continue;
        }
        else
        {
            auto it = loc[i]->get_villager_list();//watch the refrences

            for (size_t j = 0; j < it.size(); j++)
            {
                if (!find)
                {
                    option1.push_back(it[j]);
                }

                if (a.bfs(it[j]->get_currnet_location()->get_loc_relation(), mon_place).size() == 2)
                {
                    option.push_back(it[j]);
                    find = true;

                    break;
                }
            }
        }
    }
    find = false;
    for (size_t i = mon_place + 1; i < 19; i++)
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
                if (!find)
                {
                    option1.push_back(it[j]);
                }

                if (a.bfs(it[j]->get_currnet_location()->get_loc_relation(), mon_place).size() == 2)
                {
                    option.push_back(it[j]);
                    find = true;
                    break;
                }
            }
        }
    }

    auto cmp = [mon_place](villager *a, villager *b)
    {
        int va = a->get_currnet_location()->get_loc_relation();
        int vb = b->get_currnet_location()->get_loc_relation();
        return std::abs(va - mon_place) < std::abs(vb - mon_place);
    };
    if (!option.empty())
    {

        auto it = min_element(option.begin(), option.end(), cmp);
        (*it)->set_current_location(loc[mon_place]);
    }
    else
    {
        auto it=min_element(option1.begin(),option1.end(),cmp);
        (*it)->set_current_location(loc [a.bfs((*it)->get_currnet_location()->get_loc_relation(),mon_place)[1]]);
    }
}

void Hypnotic_Gaze::monster_strike(int dice_attack, int move, vector<monster *> & monsters, vector<int> & route, vector<location *> &loc, hero *h)
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if (typeid(*monsters[i]).name() == typeid(invisible_man).name())
            monster_card::monster_strike(dice_attack, move, monsters[i], route, loc, h);
    }
}
