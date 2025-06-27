#ifndef PERK_HPP
#define PERK_HPP
#include "hero.hpp"
#include "monster.hpp"
#include "location.hpp"
#include <bits/stdc++.h>
class item;
class programm;
class perk
{
public:
std::string name;
std::string get_name();
    virtual void play(hero *he, std::vector<hero *>  & he_list, monster *mo, std::vector<location *>  & loc, std::vector<item *>  & it_list, std::vector<monster *>  & mo_list, programm  & help_obj1) = 0;
    perk()=default;
    ~perk()=default;
};

#endif