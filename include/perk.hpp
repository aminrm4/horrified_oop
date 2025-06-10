#ifndef PERK_HPP
#define PERK_HPP
#include "hero.hpp"
#include "monster.hpp"
#include "item.hpp"
#include "location.hpp"
#include <bits/stdc++.h>
class perk
{
public:
    virtual void play(hero *, std::vector<hero *>, monster *,std:: vector<location *>, std::vector<item *>, std::vector<monster *>, std::vector<std::vector<int>>) = 0;
    perk()=default;
    ~perk()=default;
};

#endif