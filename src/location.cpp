#include "location.hpp"
#include "villager.hpp"
#include "item.hpp"
#include <iostream>
#include "hero.hpp"
#include "programm.hpp"
using namespace std;
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