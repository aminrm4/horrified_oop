#pragma once
#include <string>
#include <Color.hpp>
class Color;
class location;
class item
{
    int power ;
    std::string name;
     rgb::Color color;
    location * loc;
    
    public:
    item(int , std::string ,  rgb::Color , location*);
    int get_power();
    std::string get_name();
     rgb::Color get_Color();
    location* get_loc();

};