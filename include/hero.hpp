#pragma once
#include "item.hpp"
#include "location.hpp"
#include "vector"
#include "villager.hpp"
#include "perk.hpp"
#include"Invisible_man.hpp"
class villager;
class location;
class perk;
class item;
class monster;
class Drakula;
class programm;
class hero


{
    
    protected:
    location* loc;
    std::vector<villager *> villagers;
    int action;
    std::vector<item*> item_have;
    std::vector<perk*> perk_have;
    string name_of_hero;
    
    public:
    virtual void special_action(std::vector<std::vector<int>>& map , const std::vector<location*>& loc={}) = 0;
    void advance(vector<monster *> &monsters, programm &bug);
    void guide(std::vector<std::vector<int>>&  map,programm &);
    void defeat(vector<monster *> &monsters, programm &bug);
    void move(location *loc,  programm & bug,const vector<villager *> &villagers={});
    int get_action();
    void set_perks(vector<perk*> perks);
    std:: vector<perk*> get_perks();
    void set_item(vector<item*>  items);
     std::vector <item*> &get_items(); //refrenced too
    void pickup();
    void set_action(int);
    location* get_loc();
     std::vector<villager> get_villagers();
    string get_hero_name();
    hero(std::vector<perk *> &);


};