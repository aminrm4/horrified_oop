#include "Hypnotic_Gaze.hpp"
#include <bits/stdc++.h>
#include "Drakula.hpp"
using namespace std;

void Hypnotic_Gaze::event(std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &bug)
{
    vector<vector<int>> routes;
    for (int i = 0; i < bug.list_of_location.size(); i++)
    {
        for (auto vill : bug.list_of_location.at(i)->get_villager_list())
        {
            for (auto monsters : bug.monster_list)
            {
                if (typeid(*monsters).name() == typeid(Drakula).name())
                {
                    routes.push_back(bug.bfs(monsters->get_loc()->get_loc_relation(), vill->get_currnet_location()->get_loc_relation()));
                }
            }
        }
    }
    for (int i = 0; i < bug.list_of_location.size(); i++)
    {
        for (auto heros : bug.list_of_location.at(i)->get_hero_list())
        {
            for (auto monsters : bug.monster_list)
            {
                if (typeid(*monsters).name() == typeid(Drakula).name())
                {
                    routes.push_back(bug.bfs(monsters->get_loc()->get_loc_relation(), heros->get_loc()->get_loc_relation()));
                }
            }
        }
    }
    vector<int> route = *min_element(routes.begin(), routes.end(), [](vector<int> &a, vector<int> &b)
                                     { return a.size() < b.size(); });

    if (routes.size() != 0)
        for (auto heros : bug.hero_list)
        {

            heros->move(bug.list_of_location[route[1]], bug);
        }

    else
    {
        cerr << "error in monster strike when finding min move to place \n";
    }
}

void Hypnotic_Gaze::monster_strike(programm &bug, vector<monster *> &monsters)
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if (typeid(*monsters[i]).name() == typeid(invisible_man).name())
            monster_card::_strike(dice_play, move_left, bug, monsters[i]);
    }
}
void Hypnotic_Gaze::set_item(int item_count)
{
    this->item_count = item_count;
}
Hypnotic_Gaze::Hypnotic_Gaze(int dic, int my_item, int mover)
{
    item_count = my_item;
    dice_play = dic;
    move_left = mover;
}
