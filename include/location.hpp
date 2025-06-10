#ifndef LOCATION_HPP
#define LOCATION_HPP
#include <bits/stdc++.h>
#include "villager.hpp"
class location
{
protected:
    int loc_relation;
    bool coffin_exist;
    std::vector<villager *> villager_list;

public:
    void set_coffin_exist(bool);
    void set_villager(villager *);
    void set_loc_relation(int);
    int get_loc_relation() const;
    bool get_coffin_exist() const;
     std ::vector<villager *> &get_villager_list();

    location(int, bool, villager *);
    location() = delete;
    virtual ~location();
};

#endif