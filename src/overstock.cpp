#include "overstock.hpp"
#include "programm.hpp"
#include <iostream>
#include <iterator>
using namespace std;
void overstock::play(hero *he, std::vector<hero *> her_list, monster *mon, location *loc, std::vector<item *> item_list, std::vector<monster *> mon_list, std::vector<std::vector<int>> map)

{
     programm help_object;
          set<int>::iterator accesser;
          set<int>temp;
     temp = help_object.random_generator(1, 35, 2);
     accesser=temp.begin();
     auto item1 = item_list[*accesser];
     accesser++;
     auto item2 = item_list[*accesser]; // monster are players?
     loc->set_item_list(item1);
     loc->set_item_list(item2);
     item_list.erase(item_list.begin()+*accesser);
     accesser--;
     item_list.erase(item_list.begin()+*accesser);
}
