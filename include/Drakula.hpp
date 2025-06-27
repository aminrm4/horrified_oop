#pragma once
#include "monster.hpp"
class hero;
class Drakula : public monster
{
    int remain_coffin ;
    public:
    void ability(std::vector <int> & route , std::vector<location*>  & locations , hero* h);
    Drakula(int coffin, bool is_freenzy,int freenzy_order,location* ptr);
    int get_remaining_coffin();
    void set_remaining_coffin(int );
};