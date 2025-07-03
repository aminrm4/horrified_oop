#include "overstock.hpp"
#include "programm.hpp"
#include <iostream>
#include <iterator>
#include "hero.hpp"
#include "Mayor.hpp"
using namespace std;
int random_number(int min, int max);

void overstock::play(programm &help_obj1)

{

     for (int i = 0; i < help_obj1.hero_list.size(); i++)
     {
          
          int random =random_number(0,help_obj1.list_of_items.size()-1);
          help_obj1.list_of_items.at(random)->get_loc()->set_item_list(help_obj1.list_of_items.at(random));
          help_obj1.list_of_items.erase(help_obj1.list_of_items.begin() + random);
     }

     cout << "over stock played succecfully" << endl;
}
overstock::overstock()
{
     name = "overstock";
}