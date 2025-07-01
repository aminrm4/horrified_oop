#include "Hypnotic_Gaze.hpp"
#include<bits/stdc++.h>
#include"Drakula.hpp"
using namespace std;

void Hypnotic_Gaze::event(std::vector<std::vector<int>>& map,std::vector<location*>& loc , programm& a)
{
/*{   vector<int >hero_closer;
    int drakula_location=0;
    fill(hero_closer.begin(),hero_closer.end(),-1);
    for (auto her:a.hero_list )
    {   
      hero_closer.push_back( her->get_loc()->get_loc_relation());
        
    }
    for (auto mon : a.monster_list)
    {
        if (typeid(*mon).name()==typeid(Drakula).name())
        {   
        
            drakula_location=mon->get_loc()->get_loc_relation();
        }
        
    }


    int finla_min=0;
for (int  i = 0; i <hero_closer.size(); i++)
{
    if (abs(hero_closer[i]-drakula_location < abs(hero_closer[i+1]-drakula_location)))
    {
        finla_min=hero_closer[i];
        break;
    }
    else
    {
        finla_min=hero_closer[i+1];
        break;
    }
    
}
a.bfs()



 a.list_of_location[finla_min]->get_hero_list()[0]->move(a.list_of_location[finla_min+1])
*/
  
























































    // vector<int> hero_places;
    // vector<villager *> option;
    // vector<villager *> option1;
    // bool find = false;
    // int mon_place = a->get_loc()->get_loc_relation();
    // for (size_t i = mon_place - 1; i <= 0; i--)
    // {
    //     if (loc[i]->get_villager_list().empty())
    //     {
    //         continue;
    //     }
    //     else
    //     {
    //         auto it = loc[i]->get_villager_list();//watch the refrences

    //         for (size_t j = 0; j < it.size(); j++)
    //         {
    //             if (!find)
    //             {
    //                 option1.push_back(it[j]);
    //             }

    //             if (a.bfs(it[j]->get_currnet_location()->get_loc_relation(), mon_place).size() == 2)
    //             {
    //                 option.push_back(it[j]);
    //                 find = true;

    //                 break;
    //             }
    //         }
    //     }
    // }
    // find = false;
    // for (size_t i = mon_place + 1; i < 19; i++)
    // {
    //     if (loc[i]->get_villager_list().empty())
    //     {
    //         continue;
    //     }
    //     else
    //     {
    //         auto it = loc[i]->get_villager_list();

    //         for (size_t j = 0; j < it.size(); j++)
    //         {
    //             if (!find)
    //             {
    //                 option1.push_back(it[j]);
    //             }

    //             if (a.bfs(it[j]->get_currnet_location()->get_loc_relation(), mon_place).size() == 2)
    //             {
    //                 option.push_back(it[j]);
    //                 find = true;
    //                 break;
    //             }
    //         }
    //     }
    // }

    // auto cmp = [mon_place](villager *a, villager *b)
    // {
    //     int va = a->get_currnet_location()->get_loc_relation();
    //     int vb = b->get_currnet_location()->get_loc_relation();
    //     return std::abs(va - mon_place) < std::abs(vb - mon_place);
    // };
    // if (!option.empty())
    // {

    //     auto it = min_element(option.begin(), option.end(), cmp);
    //     (*it)->set_current_location(loc[mon_place]);
    // }
    // else
    // {
    //     auto it=min_element(option1.begin(),option1.end(),cmp);
    //     (*it)->set_current_location(loc [a.bfs((*it)->get_currnet_location()->get_loc_relation(),mon_place)[1]]);
    // }
}

void Hypnotic_Gaze::monster_strike(programm &bug, vector<monster *> &monsters)
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if (typeid(*monsters[i]).name() == typeid(invisible_man).name())
            monster_card::_strike(dice_play, move_left,bug ,monsters[i]);
    }
            
}
void Hypnotic_Gaze::set_item(int item_count)
{
    this->item_count = item_count;
}
Hypnotic_Gaze::Hypnotic_Gaze( int dic,int my_item,int mover)
{
    item_count=my_item;
    dice_play=dic;
    move_left=mover;
}
