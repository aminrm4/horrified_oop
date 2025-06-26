#pragma once
#include "monster.hpp"
#include "hero.hpp"

class Drakula : public monster
{
    int remain_coffin ;
    public:
    void ability(std::vector <int> & route , vector<location*>  & locations , hero* h);
    Drakula(int coffin, bool is_freenzy,int freenzy_order,location* ptr);
    int get_remaining_coffin();
    void set_remaining_coffin(int );
};