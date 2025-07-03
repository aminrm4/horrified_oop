#pragma once
#include "hero.hpp"
#include <vector>
class Mayor : public hero
{
   public:
   void special_action(vector<vector<int>>& map ,  const vector<location*> & loc);
   Mayor(int , location*,std::vector<perk *>& );
};
