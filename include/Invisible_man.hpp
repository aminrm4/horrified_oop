#pragma once
#include "monster.hpp"
#include "villager.hpp"
#include "location.hpp"
#include <vector>
#include "hero.hpp"
using namespace std;
class invisible_man : public monster
{
    int remain_hidden_item ;
    public:
    void ability(std::vector <int>  & route , vector<location*> & locations , hero* h);
    invisible_man(int remain_hidden_item, bool is_freenzy ,int freenzy_order,location* loc);
    void set_remain_hidden_item(int);
    int get_remain_hidden_item();
};