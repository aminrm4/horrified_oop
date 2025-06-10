#pragma
#include <vector>

class monster
{
    protected:
    bool is_freenzy;
    int freenzy_order;
    
    public:
    void move_to_place(std::vector <int> route);
};