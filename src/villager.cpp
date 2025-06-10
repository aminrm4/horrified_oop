#include "location.hpp"
#include "villager.hpp"
#include <iostream>
using namespace std;
void villager::set_name(std::string nam)
{
    name = nam;
}
void villager::set_current_location(location *loc)
{

    if (loc == nullptr)
    {
        throw bad_alloc();
    }
    else
    {
        current_location = loc;
    }
}
villager::villager(std::string name, location *safe, location *curr) : safe_location(safe)
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
}
villager::~villager()
{
}