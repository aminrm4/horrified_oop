#include <iostream>
#include "break_of_down.hpp"
#include "map1.hpp"
#include <bits/stdc++.h>
#include "programm.hpp"
using namespace std;
int random_number(int min, int max);

void break_of_down::play(programm &help_obj1)
{
  for (auto mo : help_obj1.monster_list)
  {
    mo->set_did_attack(true);
  }

  for (int i = 0; i < 2; i++)
  {
    int random =random_number(0,help_obj1.list_of_items.size()-1);
    help_obj1.list_of_items.at(random)->get_loc()->set_item_list(help_obj1.list_of_items.at(random)); // here has a problem
    help_obj1.list_of_items.erase(help_obj1.list_of_items.begin() + random);
  }
  cout << "break of down played succecfully" << endl;
}
break_of_down::break_of_down()
{
  name = "break_of_down";
}
