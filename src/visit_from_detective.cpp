#include <iostream>
#include "visit_from_detective.hpp"
#include "map1.hpp"
#include "programm.hpp"
#include "free_func.hpp"
#include <SFML/Graphics.hpp>
using namespace std;
void remove_hero(programm &, hero *);
void remove_villager(programm &, villager *);
void remove_monster(programm &, monster *);
void remove_item(programm &, monster *);
void message_invisible_man(bool alive);
void message_drakula(bool alive);
void visit_from_detective::play(programm &help_obj1, sf::RenderWindow &window)
{
    showCenteredTextBox(window, "enter the place want to move the invisiible man");
    int location_detect;
   location_detect=show_all_location(window, help_obj1);
    for (auto mon : help_obj1.monster_list)
    {
        if (typeid(*mon).name() == typeid(invisible_man).name())
        {
            remove_monster(help_obj1, mon);
            help_obj1.list_of_location[location_detect]->set_monster_list(mon);
            mon->set_loc(help_obj1.list_of_location[location_detect]);
            showCenteredTextBox(window,"ohh invisible man moved");
            return;
        }
    }
}
visit_from_detective::visit_from_detective()
{
    name = "VisitFromTheDetective";
}
