#pragma once
#include "monster_card.hpp"
#include "Drakula.hpp"
class programm;
using namespace std;
class Hurried_Assistant : public monster_card
{
public:
    void event(std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a);
    void monster_strike(programm &bug, vector<monster *> &monsters);
    void set_item(int item_count);
    Hurried_Assistant(int dic, int my_item, int mover);
};