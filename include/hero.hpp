#pragma
#include "item.hpp"
#include "location.hpp"
#include "vector"
#include "villager.hpp"
class hero
{
    protected:
    location* loc;
    std::vector<villager> villagers;
    
    public:
    void advance();
    void guide();
    void defeat();
    void move(location* loc , std::vector <villager> villagers = {});


};