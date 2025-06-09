#include"location.hpp"
#include<iostream>
location::location(int relation,bool coffin,villager * vill):loc_relation(relation),coffin_exist(coffin)
{
    villager_list.push_back(vill);
}
