#include"location.hpp"
#include<iostream>
location::location(int relation,bool coughen,villager * vill):loc_relation(relation),coughen_exist(coughen)
{
    villager_list.push_back(vill);
}

