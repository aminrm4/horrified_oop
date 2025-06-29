#include "overstock.hpp"
#include "programm.hpp"
#include <iostream>
#include <iterator>
#include "hero.hpp"
#include "Mayor.hpp"
using namespace std;
void overstock::play(hero *he, std::vector<hero *> &he_list, monster *mo, std::vector<location *> &loc, std::vector<item *> &it_list, std::vector<monster *> &mo_list, programm &help_obj1)

{
     for (auto her : help_obj1.hero_list)
     {
          if (typeid(*her).name() == typeid(Mayor).name())
          {
               for (int i = 0; i < 2; i++)
               {
                    srand(time(0) + i);
                    int random = rand() % help_obj1.list_of_items.size();
                    help_obj1.list_of_items.at(random)->get_loc()->set_item_list(help_obj1.list_of_items.at(random)); // here has a problem
                    help_obj1.list_of_items.erase(help_obj1.list_of_items.begin() + random);
               }
          }
          else
          {
               for (int i = 0; i < 2; i++)
               {
                    srand(time(0) + i);
                    int random = rand() % help_obj1.list_of_items.size();
                    help_obj1.list_of_items.at(random)->get_loc()->set_item_list(help_obj1.list_of_items.at(random)); // here has a problem
                    help_obj1.list_of_items.erase(help_obj1.list_of_items.begin() + random);
               }
          }
     }


     cout << "over stock played succecfully" << endl;
}
overstock::overstock()
{
     name = "overstock";
}