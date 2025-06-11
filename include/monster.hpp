#pragma once
#include <vector>
#include "location.hpp"
class monster
{
    protected:
    bool is_freenzy;
    int freenzy_order;
    location* loc;

    public:
    bool get_freenzy_status();
    void move_to_place(std::vector <int> route , int number_route , vector<location*> locations);
    void set_loc(location* );
    location* get_loc();
};