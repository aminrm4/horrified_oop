#include "Drakula.hpp"
#include <exception>
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
    remain_coffin = coffin;
    this->loc = ptr;
    
}
void Drakula::ability(std::vector <int> & route , vector<location*> & locations , hero* h)
{
    if(h == nullptr)
    throw logic_error("Cant access the hero \n");
    
    cout << "Drakula used his DarkCharm Ability and teleported you to his location \n";
    h->move(this->loc);
}
int Drakula::get_remaining_coffin()
{
    return this->remain_coffin;
}
void Drakula::set_remaining_coffin(int c)
{
    remain_coffin = c;
}
