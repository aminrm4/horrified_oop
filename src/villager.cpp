#include "location.hpp"
#include "villager.hpp"
#include <iostream>
#include "programm.hpp"
using namespace std;
namespace fs = filesystem;
int random_number(int min, int max);
void remove_villager(programm &obj, villager *v);

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
    data_saver << name << endl;
    data_saver << safe_location->get_loc_relation() << endl;
    data_saver << current_location->get_loc_relation() << endl;
    data_saver << award->get_name() << endl;
}
void villager::load_game(std::string file_name, programm &bug)
{
    fs::path dir = file_name;
    file_name = dir / "villager.txt";
    ifstream loader(file_name);
    if (!loader)
    {
        cerr << "villager file can not be load" << endl;
    }
    string nam, perk_hav;
    int saf, final;

    while (loader >> nam >> saf >> final >> perk_hav)
    {
        programm temp;

        bug.list_of_location[final]->set_villager(new villager(nam, bug.list_of_location[saf], bug.list_of_location[final], temp));
        for (int i = 0; i < bug.list_of_perks.size(); i++)
        {
            if (bug.list_of_perks[i]->get_name() == perk_hav)
            {
                bug.list_of_location[final]->get_villager_list()[0]->award = bug.list_of_perks[i]; //danger index
                bug.list_of_perks.erase(bug.list_of_perks.begin() + i);
                break;
            }
        }
    }
}
