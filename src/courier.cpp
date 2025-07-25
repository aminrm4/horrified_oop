#include "courier.hpp"
#include "programm.hpp"
#include "free_func.hpp"
#include "Archaeologist.hpp"
#include"Mayor.hpp"
#include"scientist.hpp"
#include <iostream>

void courier::special_action(std::vector<std::vector<int>> &map, programm &bug, sf::RenderWindow &window)
{
  int detect;
  showCenteredTextBox(window, "enter the hero want to teleport");
  detect = showAssetSelectionBox(window, "../Horrified_Assets/Heros");
  switch (detect)
  {
  case 0:

    for (auto l : bug.list_of_location)
    {
      cout << l->get_hero_list().size() << endl;
      if (!l->get_hero_list().empty())
      {
        for (auto h : l->get_hero_list())
        {
          if (typeid(*h).name() == typeid(Archaeologist).name())
          {
            this->move(l, bug);
            showCenteredTextBox(window, "hero has been moved to archaeologist");

            return;
          }
        }
      }
    }

    break;
  case 1:
    showCenteredTextBox(window, "you are the courier");

    break;
  case 2:
  for (auto l : bug.list_of_location)
    {
      cout << l->get_hero_list().size() << endl;
      if (!l->get_hero_list().empty())
      {
        for (auto h : l->get_hero_list())
        {
          if (typeid(*h).name() == typeid(Mayor).name())
          {
            this->move(l, bug);
            showCenteredTextBox(window, "hero has been moved to mayor");

            return;
          }
        }
      }
    }
    break;
  case 3:
  for (auto l : bug.list_of_location)
    {
      cout << l->get_hero_list().size() << endl;
      if (!l->get_hero_list().empty())
      {
        for (auto h : l->get_hero_list())
        {
          if (typeid(*h).name() == typeid(scientist).name())
          {
            this->move(l, bug);
            showCenteredTextBox(window, "hero has been moved to scientist");

            return;
          }
        }
      }
    }
    break;
  default:
    break;
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