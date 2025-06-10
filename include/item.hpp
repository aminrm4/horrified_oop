#pragma once
#include <string>
#include <Color.hpp>
#include "location.hpp"

class item
{
    int power ;
    std::string name;
    Color color;
    location * loc;
    
    public:
    item(int , std::string , Color , location*);
    int get_power();
    std::string get_name();
    Color get_Color();
    location* get_loc();

};