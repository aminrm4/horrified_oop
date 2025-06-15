#pragma once
#include "hero.hpp"
#include "monster.hpp"
#include "item.hpp"
#include "location.hpp"
#include <bits/stdc++.h>
#include "perk.hpp"
#include"programm.hpp"
class overstock:public perk
{
public:
     void play(hero *he, std::vector<hero *>&  he_list, monster *mo, std::vector<location *>  & loc, std::vector<item *> & it_list, std::vector<monster *> & mo_list, programm & help_obj1) override final;
     overstock()=default;
     ~overstock()=default;
};