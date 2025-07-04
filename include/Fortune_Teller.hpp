#pragma once
#include "monster_card.hpp"
class programm;
using namespace std;
class Fortune_Teller : public monster_card
{
public:
    void event(std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a);
    void monster_strike(programm &bug, vector<monster *> &monsters);
    void set_item(int item_count);
    Fortune_Teller(int dic, int my_item, int mover);
};