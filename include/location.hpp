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
    std::vector<hero *>hero_list;
    std::vector<monster*>monster_list;

public:
    void set_coffin_exist(bool);
    void set_villager(villager *);
    void set_loc_relation(int);
     void set_item_list(item*);
     void set_hero_list(hero*);
     void set_monster_list(monster*);
    int get_loc_relation() const;
    bool get_coffin_exist() const;
     std ::vector<villager *> get_villager_list();
    std::vector<item*>  get_item_list();
    std::vector<hero*> get_hero_list();
    std::vector<monster*> get_monster_list();
    location(int relation, bool coffin, villager *vill,item * item_lis,hero*her_list,monster*mon_list);
    location() = delete;
    ~location();
    void delete_item();
    void delete_villager_list();
    void delete_monster_list();
   
};

#endif