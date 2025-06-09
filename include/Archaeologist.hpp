#pragma
#include "hero.hpp"

class Archaeologist : public hero
{
    int action;
    std::vector<item*> item_have;
    std::vector<perk*> perk_have;

    public: 
    void special_action(std::vector<std::vector<int>> map);
};