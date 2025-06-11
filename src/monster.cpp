#include "monster.hpp"
using namespace std;
void monster::move_to_place(std::vector <int> route , int number_route , vector<location*> locations)
{
    if(!locations.empty() || !route.empty() )
        throw invalid_argument("invalid input\n");
    if(number_route >= route.size())
        number_route = route.size()-1;

    for(auto locationIndex: locations)
        if(route[number_route] == locationIndex->get_loc_relation())
            this->loc=locationIndex;

    cout << "Drakula moved to location number "<<route[number_route]<<endl;
}
void monster::set_loc(location* loc)
{
    if(loc == nullptr)
    throw invalid_argument("invalid argument");
    this->loc = loc;
}
location* monster::get_loc()
{
    return this->loc;
}
bool monster::get_freenzy_status()
{
    return this->is_freenzy;
}