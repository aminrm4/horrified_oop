#include "monster.hpp"
#include <stdexcept>
#include "location.hpp"
#include "Drakula.hpp"
#include "programm.hpp"
using namespace std;
void monster::move_to_place(std::vector<int> &route, int number_route, vector<location *> &locations , programm &bug)
{
    if (!locations.empty() || !route.empty())
        throw invalid_argument("invalid input\n");
    if (number_route >= route.size())
        {
         number_route = route.size() - 1;
            if(typeid(*this).name() == typeid(Drakula).name())
                {
                    bug.set_night_terror(bug.get_night_terror()+1);
                }
        }
    for (auto locationIndex : locations)
        if (route[number_route] == locationIndex->get_loc_relation())
            this->loc = locationIndex;

    cout << "Drakula moved to location number " << route[number_route] << endl;
}
void monster::set_loc(location *loc)
{
    if (loc == nullptr)
        throw invalid_argument("invalid argument");
    this->loc = loc;
}
location *monster::get_loc()
{
    return this->loc;
}
bool monster::get_freenzy_status()
{
    return this->is_freenzy;
}
bool monster::get_is_frenzy()
{
    return is_freenzy;
}
int monster::get_frenzy_order()
{
    return freenzy_order;
}
void monster::set_is_frenzy(bool frenz)
{
    is_freenzy = frenz;
}
void monster::set_frenzy_order(int frenz)
{
    freenzy_order = frenz;
}
string monster::get_mons_name()
{
    return name_of_monster;
}
int & monster::get_hidden_item()
{
    return totla_hidden_item;
}
bool monster::get_did_attack()
{
    return did_attack;
}
void monster::set_did_attack(int did_attack)
{
    this->did_attack = did_attack;
}