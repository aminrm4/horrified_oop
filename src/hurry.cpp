#include <iostream>
#include "hurry.hpp"
#include "programm.hpp"
#include <iostream>
#include <string>
#include "Drakula.hpp"
#include "Invisible_man.hpp"
#include "Mayor.hpp"
#include "Archaeologist.hpp"
using namespace std;
void remove_hero(programm &, hero *);
void remove_villager(programm &, villager *);
void remove_monster(programm &, monster *);
void remove_item(programm &, monster *);
void message_invisible_man(bool alive);
void message_drakula(bool alive);
void hurry::play(programm &help_obj1)
{
    // fake vill

    for (auto her : help_obj1.hero_list)
    {
        if (typeid(*her).name() == typeid(Mayor).name())
        {
            cout << "this is for Mayor" << endl;
        }
        if (typeid(*her).name() == typeid(Archaeologist).name())
        {
            cout << "this is for Archeaologist" << endl;
        }
        for (auto maper : help_obj1.my_map[her->get_loc()->get_loc_relation()])
        {
            cout << maper << " ";
        }

        cout << endl;
        int new_loc;
        cout << "enter the location " << endl;
        cin >> new_loc;
        for (auto maper : help_obj1.my_map[her->get_loc()->get_loc_relation()])
        {
            if (maper == new_loc)
            {
                her->move(help_obj1.list_of_location[new_loc], help_obj1, her->get_villagers());
                cout <<"you moved succesfully" << endl;
            }
        }
    }

    for (auto her : help_obj1.hero_list)
    {
        if (typeid(*her).name() == typeid(Mayor).name())
        {
            cout << "this is for Mayor" << endl;
        }
        if (typeid(*her).name() == typeid(Archaeologist).name())
        {
            cout << "this is for Archeaologist" << endl;
        }
        for (auto maper : help_obj1.my_map[her->get_loc()->get_loc_relation()])
        {
            cout << maper << " ";
        }

        cout << endl;
        int new_loc;
        cout << "enter the location " << endl;
        cin >> new_loc;
        for (auto maper : help_obj1.my_map[her->get_loc()->get_loc_relation()])
        {
            if (maper == new_loc)
            {
                her->move(help_obj1.list_of_location[new_loc], help_obj1, her->get_villagers());
                cout << " you moved succesfully" << endl;
            }
        }
    }
}
hurry::hurry()
{
    name = "hurry";
}
