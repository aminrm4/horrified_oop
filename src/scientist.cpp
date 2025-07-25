#include"scientist.hpp"
#include<iostream>
#include<SFML/Graphics.hpp>
#include"free_func.hpp"
using namespace std;
 void  scientist::special_action(std::vector<std::vector<int>> &map,programm & bug,sf::RenderWindow & window)
 {
   showCenteredTextBox(window,"you have ability sir not special action ");
    this->set_action(this->get_action()+1);


 }
   scientist ::scientist(int actions, location * starting_loc, std::vector<perk *> & perks):hero(perks)
   {
     if (actions < 0)
        throw logic_error("invalid actions \n");
    this->action = actions;
    swap(loc, starting_loc);
    name_of_hero = "scientist";
   }
