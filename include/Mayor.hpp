#pragma once
#include "hero.hpp"
#include <vector>
class Mayor : public hero
{
   void special_action(vector<vector<int>>& map ,  const vector<location*> & loc={});
};
