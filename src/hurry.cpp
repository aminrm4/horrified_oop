#include <iostream>
#include "hurry.hpp"
#include "programm.hpp"
#include <iostream>
#include <string>
#include "Drakula.hpp"
#include "Invisible_man.hpp"
#include "Mayor.hpp"
#include "Archaeologist.hpp"
#include <SFML/Graphics.hpp>
#include "free_func.hpp"
#include "courier.hpp"
#include "scientist.hpp"
using namespace std;
void remove_hero(programm &, hero *);
void remove_villager(programm &, villager *);
void remove_monster(programm &, monster *);
void remove_item(programm &, monster *);
void message_invisible_man(bool alive);
void message_drakula(bool alive);
void hurry::play(programm &help_obj1, sf::RenderWindow &window, hero *her)
{
    for (auto herr : help_obj1.hero_list)
    {
        showCenteredTextBox(window, "enter the " + herr->get_hero_name() + " to move :");
        for (int i = 0; i < 2; i++)
        {
            herr->move(help_obj1.list_of_location[showLocationTextBox(window, help_obj1, *her)], help_obj1);
            showCenteredTextBox(window,"moved succesfully");
        }
    }
}
hurry::hurry()
{
    name = "Hurry";
}
