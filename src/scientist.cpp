#include"scientist.hpp"
#include<iostream>
using namespace std;
 void  scientist::special_action(std::vector<std::vector<int>> &map,programm & bug)
 {
    cout<<"ohhhhh scientist does not have a any special action thats a ability"<<endl;

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
