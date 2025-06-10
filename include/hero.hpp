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
    
    public:
    virtual void special_action(vector<vector<int>>& map , vector<location*> loc) = 0;
    void advance(Drakula D , invisible_man I);
    void guide(vector<vector<int>> map);
    void defeat(Drakula* D , invisible_man* I);
    void move(location* loc , std::vector <villager*> villagers = {});
    int get_action();
    location* get_loc();
    vector<villager> get_villagers();


};