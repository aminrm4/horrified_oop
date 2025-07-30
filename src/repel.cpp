#include <iostream>
#include "repel.hpp"
#include "Drakula.hpp"
#include "Invisible_man.hpp"
#include "programm.hpp"
#include "map1.hpp"
#include <SFML/Graphics.hpp>
#include "free_func.hpp"
#include "Mayor.hpp"
#include "Archaeologist.hpp"
#include "courier.hpp"
#include "scientist.hpp"
using namespace std;
void remove_hero(programm &, hero *);
void remove_villager(programm &, villager *);
void remove_monster(programm &, monster *);
void remove_item(programm &, monster *);
void message_invisible_man(bool alive);
void message_drakula(bool alive);
void repel::play(programm &help_obj1, sf::RenderWindow &window, hero *her)
{
  int new_loc = 0;
  for (auto moo : help_obj1.monster_list)
  {
    showCenteredTextBox(window, "enter the " + moo->get_mons_name() + " to move :");
    for (int i = 0; i < 2; i++)
    {
      new_loc = show_monster_location(window, help_obj1, moo);
      remove_monster(help_obj1, moo);
      help_obj1.list_of_location[new_loc]->set_monster_list(moo);
      moo->set_loc(help_obj1.list_of_location[new_loc]);
          showCenteredTextBox(window, "moved succesfully");
    }
  }
}
repel::repel()
{
  name = "Repel";
}