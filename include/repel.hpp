#pragma once
#include "hero.hpp"
#include "monster.hpp"
#include "item.hpp"
#include "location.hpp"
#include <bits/stdc++.h>
#include "perk.hpp"
class repel : public perk
{
public:
     void play(hero *, std::vector<hero *>, monster *, location *, std::vector<item *>, std::vector<monster *>, std::vector<std::vector<int>>) override final;

     repel() = default;
     ~repel() = default;
};   