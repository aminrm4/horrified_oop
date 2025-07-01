#pragma once
#include "monster_card.hpp"
class programm;
using namespace std;
class form_of_the_bat : public monster_card
{
    

public:
    void event(perk *p, hero *hero, monster *m, std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &);
    void monster_strike(int dice_attack, int move, programm &, vector<monster *> &monsters, vector<int> &route, vector<location *> &loc, hero *h);
    void set_item(int item_count);
    int get_item();
    form_of_the_bat(int dic,int my_item,int mover);
};