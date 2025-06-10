#include "location.hpp"
#include "villager.hpp"
#include "item.hpp"
#include <iostream>
using namespace std;
location::location(int relation, bool coffin, villager *vill,item * item_lis)
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
    if (vill == nullptr)
    {
        throw bad_alloc();
    }
    else
    {
        villager_list.push_back(vill);
    }
}
void location::set_loc_relation(int rel)
{
    if (rel <= 0)
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
 vector<villager *> &location::get_villager_list() 
{
    return villager_list;
}
location::~location()
{
}
    vector<item*> & location:: get_item_list()
    {
        return item_list;
    }
     void  location ::set_item_list(item* li)
     {
        if (li==nullptr)
        {
            throw bad_alloc();
        }
        else
        {
            item_list.push_back(li);
        }
        
     }
