#ifndef LOCATION_HPP
#define LOCATION_HPP
#include<bits/stdc++.h>
#include"villager.hpp"
class location
{
protected:
 int loc_relation;
bool coffin_exist;
std::vector<villager *> villager_list;


public:
    virtual void set_coffin_exist(bool)=0;
    virtual void set_viliger(villager)=0;
    virtual void set_loc_relation(int )=0;  
    location(int ,bool,villager *);
    location()=delete;
    virtual ~location();


};


#endif