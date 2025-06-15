#include "overstock.hpp"
#include "programm.hpp"
#include <iostream>
#include <iterator>
using namespace std;
void overstock::play(hero *he, std::vector<hero *>&  he_list, monster *mo, std::vector<location *>&  loc, std::vector<item *> & it_list, std::vector<monster *> & mo_list, programm & help_obj1)

{
     programm help_object;
          set<int>::iterator accesser;
          set<int>temp;
     temp = help_object.random_generator(1, 35, 2);
     accesser=temp.begin();
     auto item1 = it_list[*accesser];
     item1->get_loc()->set_item_list(item1);
     accesser++;
     auto item2 = it_list[*accesser]; // monster are players?
     item2->get_loc()->set_item_list(item2);
     it_list.erase(it_list.begin()+*accesser);
     accesser--;
     it_list.erase(it_list.begin()+*accesser);

}
