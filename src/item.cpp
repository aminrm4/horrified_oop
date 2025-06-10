#include "item.hpp"
#include <exception>

item::item(int power , std::string name , Color color , location* loc)
{
    if(power <=0)
    throw std::logic_error("invalid power \n");
    
    this->power = power;
    this->name = name;
    this->color = color;
    this->loc = loc;
}
int item::get_power()
{
    return power;
}
std::string item::get_name()
{
    return name;
}
Color item::get_Color()
{
    return color;
}

location* item::get_loc()
{
    return loc;
}

