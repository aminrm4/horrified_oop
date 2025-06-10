#pragma once
#include "item.hpp"
#include "location.hpp"
#include "vector"
#include "villager.hpp"
#include "perk.hpp"
class hero
{
    protected:
    location* loc;
    std::vector<villager> villagers;
    
    public:
    void advance();
    void guide(vector<vector<int>> map);
    void defeat();
    void move(location* loc , std::vector <villager*> villagers = {});
    location* get_loc();
    vector<villager> get_villagers();


};