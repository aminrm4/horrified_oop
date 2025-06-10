#pragma once
#include "monster.hpp"
#include "villager.hpp"
#include "location.hpp"

class invisible_man : public monster
{
    int remain_hidden_item ;
    public:
    void stalk_unseen(villager *);
    invisible_man(int remain_hidden_item, bool is_freenzy ,int freenzy_order,location* loc);
};