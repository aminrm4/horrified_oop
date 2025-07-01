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
    virtual void play(programm &help_obj1) = 0;
    perk()=default;
    virtual~perk()=default;
};

#endif