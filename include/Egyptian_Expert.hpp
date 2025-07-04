#pragma once
#include "monster_card.hpp"
#include "programm.hpp"
#include <vector>
class Egyptian_Expert : public monster_card
{

public:
    void event(std::vector<std::vector<int>> &map, std::vector<location *> &loc, programm &a);
    void monster_strike(programm &bug, vector<monster *> &monsters);
    void set_item(int item_count);
    Egyptian_Expert(int dic, int my_item, int mover);
};
