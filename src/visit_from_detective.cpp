#include <iostream>
#include "visit_from_detective.hpp"
#include "map1.hpp"
#include"programm.hpp"
using namespace std;
void visit_from_detective::play(hero *he, std::vector<hero *> & he_list, monster *mo, std::vector<location *>&  loc, std::vector<item *> & it_list, std::vector<monster *> & mo_list, programm & help_obj1)
{

    cout << "enter the place for moving the invisible man :" << endl;
    int location_detect;
    cin >> location_detect;
    map1 router = static_cast<map1>(location_detect);
  
            mo->set_loc(loc[static_cast<int>(router)]);
            
}
