#include <iostream>
#include "break_of_down.hpp"
#include "map1.hpp"
#include <bits/stdc++.h>
#include "programm.hpp"
using namespace std;
void break_of_down::play(hero *he, std::vector<hero *>&  he_list, monster *mo, std::vector<location *>  & loc, std::vector<item *> & it_list, std::vector<monster *>&  mo_list, programm & help_obj1)
{
   
    for (int i = 0; i < 2; i++)
  {
    srand(time(0) + i);
    int random = rand() % help_obj1.list_of_items.size();
   help_obj1. list_of_items.at(random)->get_loc()->set_item_list(help_obj1. list_of_items.at(random)); // here has a problem
   help_obj1. list_of_items.erase(help_obj1. list_of_items.begin() + random);
  }
  cout<<"break of down played succecfully"<<endl;
}
    break_of_down::break_of_down()
    {
      name="break_of_down";
    } 
