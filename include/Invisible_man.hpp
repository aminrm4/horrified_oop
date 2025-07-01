#pragma once
#include "monster.hpp"
#include "villager.hpp"
#include "location.hpp"
#include <vector>
class hero;
class programm;
using namespace std;
class invisible_man : public monster
{
    public:
    void ability(programm & bug);
    invisible_man(int remain_hidden_item, bool is_freenzy ,int freenzy_order,location* loc);
    void set_remain_hidden_item(int);
};