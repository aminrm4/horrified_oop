#include "location.hpp"
#include "villager.hpp"
#include "item.hpp"
#include <iostream>
#include "hero.hpp"
#include "programm.hpp"
using namespace std;
namespace fs = filesystem;
location::location(int relation, bool coffin)

{
    try
    {

        set_loc_relation(relation);
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
    }
    set_coffin_exist(coffin);
}

void location::set_coffin_exist(bool num)
{
    coffin_exist = num;
}
void location::set_villager(villager *vill)
{

    villager_list.push_back(vill);
}
void location::set_loc_relation(int rel)
{
    if (rel < 0)
    {
        throw invalid_argument("bad relatonship entered \n");
    }
    else
    {
        loc_relation = rel;
    }
}

int location::get_loc_relation() const
{
    return loc_relation;
}
bool location::get_coffin_exist() const
{
    return coffin_exist;
}
vector<villager *> &location ::get_villager_list()
{
    return villager_list;
}

vector<item *> &location::get_item_list()
{
    return item_list;
}
void location ::set_item_list(item *li)
{

    item_list.push_back(li);
}
void location::set_hero_list(hero *hi)
{

    hero_list.push_back(hi);
}
void location::set_monster_list(monster *mo)
{

    monster_list.push_back(mo);
}

vector<hero *> &location::get_hero_list()
{
    return hero_list;
}
vector<monster *> &location::get_monster_list()
{
    return monster_list;
}
void location::delete_item()
{
    item_list.clear();
}
void location::delete_villager_list()
{
    villager_list.clear();
}
void location ::delete_monster_list()
{
    monster_list.clear();
}

void remove_hero(programm &obj, hero *h)
{
    for (int i = 0; i < obj.list_of_location.size(); i++)
    {

        auto it = std::find(obj.list_of_location[i]->get_hero_list().begin(), obj.list_of_location[i]->get_hero_list().end(), h);
        if (it != obj.list_of_location[i]->get_hero_list().end())
        {
            obj.list_of_location[i]->get_hero_list().erase(it);
            return;
        }
    }
}

void remove_monster(programm &obj, monster *m)
{
    for (int i = 0; i < obj.list_of_location.size(); i++)
    {

        auto it = std::find(obj.list_of_location[i]->get_monster_list().begin(), obj.list_of_location[i]->get_monster_list().end(), m);
        if (it != obj.list_of_location[i]->get_monster_list().end())
        {
            obj.list_of_location[i]->get_monster_list().erase(it);
            return;
        }
    }
}
void remove_villager(programm &obj, villager *v)
{
    for (int i = 0; i < obj.list_of_location.size(); i++)
    {

        auto it = std::find(obj.list_of_location[i]->get_villager_list().begin(), obj.list_of_location[i]->get_villager_list().end(), v);
        if (it != obj.list_of_location[i]->get_villager_list().end())
        {
            obj.list_of_location[i]->get_villager_list().erase(it);
            return;
        }
    }
}

void remove_item(programm &obj, item *v)
{
    for (int i = 0; i < obj.list_of_location.size(); i++)
    {

        auto it = std::find(obj.list_of_location[i]->get_item_list().begin(), obj.list_of_location[i]->get_item_list().end(), v);
        if (it != obj.list_of_location[i]->get_item_list().end())
        {
            obj.list_of_location[i]->get_item_list().erase(it);
            return;
        }
    }
}
location::~location()
{
    for (auto items : item_list)
    {
        delete items;
    }
    for (auto villagers : villager_list)
    {
        delete villagers;
    }

    villager_list.clear();
    item_list.clear();
    hero_list.clear();
    monster_list.clear();
}
void location::save_game(std::string file_name)
{
    ofstream saver(file_name, ios::app);
    if (!saver)
    {
        cerr << "location file can not be opend" << endl;
    }
    for (auto it : this->get_item_list())
    {
        saver << this->get_loc_relation() << " ";

        saver << it->get_name() << endl;
    }
    saver.close();
}
void location::load_game(std::string file_name, programm &bug)
{
    string vill_file_name = file_name;

    fs::path dir = file_name;
    file_name = dir / "location.txt";
    ifstream loader(file_name);
    if (!loader)
    {
        throw invalid_argument("location file could not open");
    }

    int lo;
    string nam;
    while (loader >> lo >> nam)
    {
        
        for (int i = 0; i < bug.list_of_items.size(); i++)
        {

            if (bug.list_of_items[i]->get_name() == nam)
            {
                bug.list_of_location[lo]->set_item_list(bug.list_of_items[i]);
                bug.list_of_items.erase(bug.list_of_items.begin() + i);
                break;
            }
        }

    }
    
    loader.close();

    fs::path dir_v = vill_file_name;
    vill_file_name = dir_v / "villager.txt";
    ifstream loader_vil(vill_file_name);
    string vil_name, perk_hav;
    int saf, final;
    int count = 0;
    while (loader_vil >> vil_name >> saf >> final >> perk_hav)
    {
        programm temp;

        bug.list_of_location[final]->set_villager(new villager(vil_name, bug.list_of_location[saf], bug.list_of_location[final], temp));
        for (int i = 0; i < bug.list_of_perks.size(); i++)
        {
            if (bug.list_of_perks[i]->get_name() == perk_hav)
            {
                count = bug.list_of_location[final]->get_villager_list().size();
                bug.list_of_location[final]->get_villager_list()[count - 1]->set_award(bug.list_of_perks[i]); // danger index
                bug.list_of_perks.erase(bug.list_of_perks.begin() + i);
                break;
            }
        }
    }
    loader_vil.close();
}
