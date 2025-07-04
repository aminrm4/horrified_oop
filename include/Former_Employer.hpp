#pragma once
#include "monster_card.hpp"
class programm;
using namespace std;
class Former_Employer : public monster_card
{

public:
    void event(std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a);
    void monster_strike(programm &bug, vector<monster *> &monsters);
    void set_item(int item_count);
    Former_Employer(int, int, int mover);
};