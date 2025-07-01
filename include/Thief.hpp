#pragma once
#include "monster_card.hpp"
#include"Drakula.hpp"
class programm;
using namespace std;
class Thief : public monster_card
{
    public:
    void event(std::vector<std::vector<int>>& map,std::vector<location*>& loc , programm& a);            //the portotype of a pure virtual function shold be exactly same in their child ..forgot programm
    void monster_strike(programm &bug, vector<monster *> &monsters);
    void set_item(int item_count);
        Thief(int dic,int my_item,int mover);
};