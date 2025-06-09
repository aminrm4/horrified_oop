#ifndef VILLAGER_HPP
#define VILIIAGER_HPP
#include<string>
#include<iostream>
#include"location.hpp"
class villager
{
private:
std::string name;
const location * safe_location;
location *current_location;
public:
void set_name(std::string);
void set_current_location();
villager(std::string);




};





#endif