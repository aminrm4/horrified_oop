#pragma once
#include "item.hpp"
#include "location.hpp"
#include "vector"
#include "villager.hpp"
#include "perk.hpp"
#include"Drakula.hpp"
#include"Invisible_man.hpp"
class hero
{
    
    protected:
    location* loc;
    std::vector<villager> villagers;
    int action;
    std::vector<item*> item_have;
    std::vector<perk*> perk_have;
    string name_of_hero;
    
    public:
    virtual void special_action(vector<vector<int>>& map , const vector<location*>  & loc={}) = 0;
    void advance(Drakula & D , invisible_man & I);
    void guide(vector<vector<int>>&  map);
    void defeat(Drakula* D , invisible_man* I , vector<monster*>& monsters);
    void move(location* loc , const std::vector <villager*>& villagers={});
    int get_action();
    void set_perks(vector<perk*> perks);
    vector<perk*> get_perks();
    void set_item(vector<item*>  items);
    vector <item*> get_items();
    void pickup();
    void set_action(int);
    location* get_loc();
    vector<villager> get_villagers();
    string get_hero_name();


};