#ifndef LOCATION_HPP
#define LOCATION_HPP
#include <bits/stdc++.h>
#include "villager.hpp"
#include"item.hpp"
class location
{
private:
    int loc_relation;
    bool coffin_exist;
    std::vector<villager *> villager_list;
    std::vector<item*> item_list;

public:
    void set_coffin_exist(bool);
    void set_villager(villager *);
    void set_loc_relation(int);
     void set_item_list(item*);
    int get_loc_relation() const;
    bool get_coffin_exist() const;
     std ::vector<villager *> &get_villager_list();
    std::vector<item*> & get_item_list();
    location(int, bool, villager *,item * );
    location() = delete;
    ~location();
};

#endif