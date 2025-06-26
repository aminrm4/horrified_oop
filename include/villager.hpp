#ifndef VILLAGER_HPP
#define VILLAGER_HPP
#include <string>
#include <iostream>
#include"programm.hpp"
class location;
class villager
{
private:
    std::string name;
    location *const safe_location;
    location *current_location;
    perk * award;

public:
    void set_name(std::string);
    void set_current_location(location *);
    villager(std::string, location *, location *,programm &  help_object);
    ~villager();
    villager() = delete;
    location * get_currnet_location();
    location * const  get_safe_location();
        perk * drop_the_perk();
        string get_name();


};

#endif
