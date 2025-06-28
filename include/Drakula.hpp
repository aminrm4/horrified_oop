#pragma once
#include "monster.hpp"
class programm;
class hero;
class Drakula : public monster
{

    public:
    void ability(std::vector <int> & route ,programm &, std::vector<location*>  & locations , hero* h);
    Drakula(int coffin, bool is_freenzy,int freenzy_order,location* ptr);
};