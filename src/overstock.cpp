#include "overstock.hpp"
#include"programm.hpp"
#include <iostream>
#include<iterator>
using namespace std;
void overstock::play(hero * he, std::vector<hero *>her_list, monster * mon, location * loc, std::vector<item *> item_list, std::vector<monster *> mon_list, std::vector<std::vector<int>> map)

{
     programm help_object;
     auto it=help_object.random_generator(1,35);
     auto item1= item_list[it.first]->get_loc();
     auto item2=item_list[it.second]->get_loc();          //monster are players? 
     //auto child_saver=dynamic_cast<i>(loc);  

}
