#include "location.hpp"
#include "villager.hpp"
#include <iostream>
#include "programm.hpp"
using namespace std;
int random_number(int min, int max);

void villager::set_name(std::string nam)
{
    name = nam;
}
void villager::set_current_location(location *loc)
{

    current_location = loc;
}
villager::villager(std::string name, location *safe, location *curr, programm &help_object1) : safe_location(safe)
{
    set_name(name);
    try
    {
        set_current_location(curr);
    }
    catch (invalid_argument &e)
    {
        cerr << "erro happend in seting villager locations" << endl;
    }
    int it = random_number(0, help_object1.list_of_perks.size() - 1);
    award = help_object1.set_award(it);
    help_object1.list_of_perks.erase(help_object1.list_of_perks.begin() + it);
}
location *villager::get_currnet_location()
{
    return current_location;
}
location *const villager::get_safe_location()
{
    return safe_location;
}
perk *villager::drop_the_perk()
{
    return award;
}
string villager::get_name()
{
    return name;
}
villager::~villager()
{
    current_location = safe_location = nullptr;
    award = nullptr;
}
void villager::save_game(string file_name)
{

    ofstream data_saver(file_name, ios::app);
    if (!data_saver)
    {
        cerr << "villager file can not be opend" << endl;
    }
    data_saver<<name<<endl;
    data_saver<<safe_location->get_loc_relation()<<endl;
    data_saver<<current_location->get_loc_relation()<<endl;
    data_saver<<award->get_name()<<endl;
}
