#ifndef LOCATION_HPP
#define LOCATION_HPP
#include<bits/stdc++.h>
#include"villager.hpp"
class location
{
  
protected:
  int loc_relation;
  bool coughen_exist;
  std::vector<villager *> villager_list;

  location(const int , bool , villager *);
  location()=delete;


public:
  virtual void set_coughen_exist(bool)=0;
  virtual void set_viliger(villager *)=0;
  virtual void set_loc_relation(int )=0;  

};


#endif