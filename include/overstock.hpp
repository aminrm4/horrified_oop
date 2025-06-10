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
     void play(hero *, std::vector<hero *>, monster *, location *, std::vector<item *>, std::vector<monster *>, std::vector<std::vector<int>>) override final;
     overstock()=default;
     ~overstock()=default;
};