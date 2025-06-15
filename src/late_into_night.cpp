#include"late_into_night.hpp"
#include<iostream>
#include<typeinfo>
#include"Mayor.hpp"
#include"Archaeologist.hpp"
using namespace std;
    void  late_into_night::play(hero *he, std::vector<hero *> & he_list, monster *mo, std::vector<location *> & loc, std::vector<item *>& it_list, std::vector<monster *>&  mo_list, programm & help_obj1)
    {
        if (typeid(*he)==typeid(Mayor))
        {
            he->set_action(he->get_action()+2);
        }
          else
        {
            throw invalid_argument("hero deos not exist\n");
        }
        if (typeid(*he)==typeid(Archaeologist))
        {
            he->set_action(he->get_action()+2);
        }
        else
        {
            throw invalid_argument("hero deos not exist\n");
        }
        

    }
