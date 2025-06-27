#pragma once
#include "monster_card.hpp"
#include"Drakula.hpp"
using namespace std;
class Thief : public monster_card
{
    public:
    void event(perk * p,hero* hero, monster *m,std::vector<std::vector<int>>& map,std::vector<location*>& loc , programm& a);            //the portotype of a pure virtual function shold be exactly same in their child ..forgot programm
    void monster_strike(int dice_attack,int move, vector<monster*> & monsters , vector<int>  & route , vector<location*>&loc , hero* h );
};