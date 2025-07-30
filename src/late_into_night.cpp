#include "late_into_night.hpp"
#include <iostream>
#include <typeinfo>
#include "Mayor.hpp"
#include "Archaeologist.hpp"
#include<SFML/Graphics.hpp>
#include"free_func.hpp"
using namespace std;
void late_into_night::play(programm &help_obj1,sf::RenderWindow & window,hero*her)
{
showCenteredTextBox(window,"your action increased 2 unit");
her->set_action(her->get_action()+2);
showCenteredTextBox(window,"late into the night used");
}

late_into_night::late_into_night()
{
    name = "LateIntoTheNight";
}
