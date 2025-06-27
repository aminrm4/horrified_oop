#include "location.hpp"
#include "villager.hpp"
#include "item.hpp"
#include <iostream>
#include "hero.hpp"
using namespace std;
location::location(int relation, bool coffin, villager *vill, item *item_lis, hero *her_list, monster *mon_list)
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
    try
    {
        set_hero_list(her_list);
        set_monster_list(mon_list);
        set_villager(vill);
        set_item_list(item_lis);
    }
    catch (bad_alloc &e)
    {
        cerr << "erro happend in seting villagers" << endl;
    }
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
    if (rel <0)
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
vector<villager *> location::get_villager_list()
{
    return villager_list;
}
location::~location()
{
}
vector<item *> location::get_item_list()
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

vector<hero *> location::get_hero_list()
{
    return hero_list;
}
vector<monster *> location::get_monster_list()
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
