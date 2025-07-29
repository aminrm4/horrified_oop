#include <iostream>
#include "repel.hpp"
#include "Drakula.hpp"
#include "Invisible_man.hpp"
#include "programm.hpp"
#include "map1.hpp"

using namespace std;
void remove_hero(programm &, hero *);
void remove_villager(programm &, villager *);
void remove_monster(programm &, monster *);
void remove_item(programm &, monster *);
void message_invisible_man(bool alive);
void message_drakula(bool alive);
void repel::play(programm &help_obj1)
{

  for (auto mon : help_obj1.monster_list)
  {
    if (typeid(*mon).name()==typeid(Drakula).name())
    {
      cout<<"this is for Drakula"<<endl;
    }
     if (typeid(*mon).name()==typeid(invisible_man).name())
    {
      cout<<"this is for Invisible man"<<endl;
    }
    for (auto maper : help_obj1.my_map[mon->get_loc()->get_loc_relation()])
    {
      cout << maper << " ";
    }

    cout << endl;
    int new_loc;
    cout<<"enter the location "<<endl;
    cin >> new_loc;
    for (auto maper : help_obj1.my_map[mon->get_loc()->get_loc_relation()])
    {
      if (maper == new_loc)
      {
        remove_monster(help_obj1, mon);
        help_obj1.list_of_location[new_loc]->set_monster_list(mon);
        mon->set_loc(help_obj1.list_of_location[new_loc]);
        cout << "first monster moved  get ready for the new one" << endl;
      }
    }
  }

  for (auto mon : help_obj1.monster_list)
  {

    for (auto maper : help_obj1.my_map[mon->get_loc()->get_loc_relation()])
    {
      cout << maper << " ";
    }

    cout << endl;
    cout << "enter the location want to move " << endl;
    int new_loc;
    cin >> new_loc;
    for (auto maper : help_obj1.my_map[mon->get_loc()->get_loc_relation()])
    {
      if (maper == new_loc)
      {
        remove_monster(help_obj1, mon);
        help_obj1.list_of_location[new_loc]->set_monster_list(mon);
        mon->set_loc(help_obj1.list_of_location[new_loc]);
        cout << "first monster moved " << endl;
      }
    }
  }

 
}
 repel::repel()
  {
    name = "Repel";
  }