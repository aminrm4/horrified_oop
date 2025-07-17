#include "courier.hpp"
#include"programm.hpp"
#include <iostream>

void courier::special_action(std::vector<std::vector<int>> &map,programm & bug)
{
   for (auto lo : bug.list_of_location)
   {
        if (!lo->get_hero_list().empty())
        {
            this->move(lo,bug);
            return;
        }
        
   }
   
}
courier ::courier(int actions, location *starting_loc, std::vector<perk *> &perks) : hero(perks)
{
    if (actions < 0)
        throw logic_error("invalid actions \n");
    action = actions;
    swap(loc, starting_loc);
    name_of_hero = "courier";
}