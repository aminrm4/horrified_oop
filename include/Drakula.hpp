#pragma once
#include "monster.hpp"
#include "hero.hpp"

class Drakula : public monster
{
    int remain_coffin ;
    public:
    void Dark_charm(hero*);
    Drakula(int coffin, bool is_freenzy,int freenzy_order,location* ptr);
};