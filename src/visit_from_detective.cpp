#include <iostream>
#include "visit_from_detective.hpp"
#include "map1.hpp"
#include"programm.hpp"
using namespace std;
void remove_hero(programm &, hero *);
void remove_villager(programm &, villager *);
void remove_monster(programm &, monster *);
void remove_item(programm &, monster *);
void message_invisible_man(bool alive);
void message_drakula(bool alive);
void visit_from_detective::play(hero *he, std::vector<hero *> & he_list, monster *mo, std::vector<location *>&  loc, std::vector<item *> & it_list, std::vector<monster *> & mo_list, programm & help_obj1)
{

    cout << "enter the place for moving the invisible man :" << endl;
    int location_detect;
    cin >> location_detect;
    for (auto mon : help_obj1.monster_list)
    {
        if (typeid(*mon).name()==typeid(invisible_man).name())
        {
                remove_monster(help_obj1,mo);
                help_obj1.list_of_location[location_detect]->set_monster_list(mo);
                mo->set_loc(help_obj1.list_of_location[location_detect]);
                cout<<"ohhhhhhh invisible man moved"<<endl;
                return;
        }
        
    }
    
    map1 router = static_cast<map1>(location_detect);
  
            mo->set_loc(loc[static_cast<int>(router)]);
            
}
    visit_from_detective::visit_from_detective()
    {
        name="visit_from_detective";
    }
