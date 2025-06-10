#pragma once
#include "hero.hpp"

class Archaeologist : public hero
{

    public: 
    void special_action(std::vector<std::vector<int>>& map , vector<location*> loc);
};