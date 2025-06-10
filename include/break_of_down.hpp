#pragma once
#include "hero.hpp"
#include "monster.hpp"
#include "item.hpp"
#include "location.hpp"
#include <bits/stdc++.h>
#include "perk.hpp"
class break_of_down:public perk
{   
    public:
     void play(hero *, std::vector<hero *>, monster *, location *, std::vector<item *>, std::vector<monster *>, std::vector<std::vector<int>>) override final;
    break_of_down()=default;
    ~break_of_down()=default;


};