#include "monster.hpp"
#include <stdexcept>
#include "location.hpp"
#include "Drakula.hpp"
#include "programm.hpp"
using namespace std;
void remove_monster(programm &obj, monster *m);
namespace fs = std::filesystem;
void monster::move_to_place(std::vector<int> &route, int number_route, programm &bug)
{

    if (number_route >= route.size() - 1)
    {
        number_route = route.size() - 1;
        if (typeid(*this).name() == typeid(Drakula).name() && route.size() > 1)
        {
            bug.set_night_terror(bug.get_night_terror() + 1);
            cout << "drakula reached a hero or villager and night terror has been incread" << endl;
        }
    }
    if (route.size() == 1)
    {
        return;
    }
    for (auto locationIndex : bug.list_of_location)
        if (route[number_route] == locationIndex->get_loc_relation())
        {
            remove_monster(bug, this);
            this->loc = locationIndex;
            locationIndex->set_monster_list(this);
        }

    cout << this->get_mons_name() << " moved to location number " << route[number_route] << endl;
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
int &monster::get_hidden_item()
{
    return totla_hidden_item;
}
bool monster::get_did_attack()
{
    return did_attack;
}
void monster::set_did_attack(bool did_attack)
{
    this->did_attack = did_attack;
}
monster::~monster()
{
    loc = nullptr;
}
void monster::save_game(string file_name)
{
    ofstream data_saver(file_name, ios::app);
    if (!data_saver)
    {
        cerr << "monster file can not be opend" << endl;
    }

    data_saver << name_of_monster << endl;
    data_saver << loc->get_loc_relation() << endl;
    data_saver << totla_hidden_item << endl;
    data_saver << is_freenzy << endl;
    data_saver << did_attack << endl;
}
void monster::load_game(std::string file_name, programm &bug)
{
    fs::path dir = file_name;

    if (this->name_of_monster == "Invisible_man")
    {
        file_name = dir / "Invisible_man.txt";
    }
    else
    {
        file_name = dir / "Drakula.txt";
    }

    ifstream loader(file_name);
    if (!loader)
    {
        throw invalid_argument("monster file could not load");
    }
    loader>>this->name_of_monster;
    int reader;
    loader>>reader;
    remove_monster(bug,this);
    this->set_loc(bug.list_of_location[reader]);
    bug.list_of_location[reader]->set_monster_list(this);


    loader>>reader;
    this->totla_hidden_item=reader;

    loader>>reader;
    this->is_freenzy=reader;

    loader>>reader;
    this->set_did_attack(reader);


}
