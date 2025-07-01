#pragma once
#include "monster.hpp"
class programm;
class hero;
class Drakula : public monster
{

    public:
    void ability(programm & bug);
    Drakula(int coffin, bool is_freenzy,int freenzy_order,location* ptr);
};