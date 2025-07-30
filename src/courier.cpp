#include "courier.hpp"
#include "programm.hpp"
#include "free_func.hpp"
#include "Archaeologist.hpp"
#include "Mayor.hpp"
#include "scientist.hpp"
#include <iostream>

void courier::special_action(std::vector<std::vector<int>> &map, programm &bug, sf::RenderWindow &window)
{
  string detec_hero;
 showCenteredTextBox(window,"Great you moved to your team mate");

for (auto he : bug.hero_list)
{
  if (he->get_hero_name()!=this->get_hero_name())
  {
    this->move(he->get_loc(),bug);
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
  name_of_hero = "Courier";
}