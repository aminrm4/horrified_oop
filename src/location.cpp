#include"location.hpp"
#include<iostream>
location::location(int relation,bool coughen,villiger * vill):loc_relation(relation),coughen_exist(coughen)
{
    villiger_list.push_back(vill);
}

