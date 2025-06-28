#include "Drakula.hpp"
#include <stdexcept>
#include<iostream>
#include"hero.hpp"
using namespace std;
Drakula::Drakula(int coffin, bool is_freenzy,int freenzy_order,location* ptr)
{
    if(coffin < 0)
    throw logic_error("invalid coffin\n");
    if(ptr == NULL)
    throw logic_error("place Drakula in a valid spot\n");
    if(freenzy_order < 0)
    throw invalid_argument("invalid freenzy order\n");
    
    this->is_freenzy = is_freenzy;
    this->freenzy_order = freenzy_order;
    this->totla_hidden_item = coffin;
    this->loc = ptr;
    name_of_monster="Drakula";
}
void Drakula::ability(std::vector <int> & route ,programm & bug, vector<location*> & locations , hero* h)
{
    if(h == nullptr)
    throw logic_error("Cant access the hero \n");
    
    cout << "Drakula used his DarkCharm Ability and teleported you to his location \n";
    h->move(this->loc,bug);
}
