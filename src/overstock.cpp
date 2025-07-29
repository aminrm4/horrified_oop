#include "overstock.hpp"
#include "programm.hpp"
#include <iostream>
#include <iterator>
#include "hero.hpp"
#include "Mayor.hpp"
#include"free_func.hpp"
using namespace std;
int random_number(int min, int max);

void overstock::play(programm &help_obj1,sf::RenderWindow & window)

{
     showCenteredTextBox(window,"those item put in the map");
     for (int i = 0; i < help_obj1.hero_list.size(); i++)
     {

          int random = random_number(0, help_obj1.list_of_items.size() - 1);
          help_obj1.list_of_items.at(random)->get_loc()->set_item_list(help_obj1.list_of_items.at(random));
          showAssetInBox(window,"../Horrified_Assets/Items/General",help_obj1.list_of_items.at(random)->get_name()+".png");
          help_obj1.list_of_items.erase(help_obj1.list_of_items.begin() + random);
     }
     showCenteredTextBox(window,"overstock played successfully");
}
overstock::overstock()
{
     name = "Overstock";
}