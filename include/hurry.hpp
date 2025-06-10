#ifndef HURRY_HPP
#define HURRY_HPP
#include "hero.hpp"
#include "monster.hpp"
#include "item.hpp"
#include "location.hpp"
#include <bits/stdc++.h>
#include "perk.hpp"
class hurry : public perk
{
public:
    void play(hero *, std::vector<hero *>, monster *, location *, std::vector<item *>, std::vector<monster *>, std::vector<std::vector<int>>) override final;
    hurry()=default;
    ~hurry()=default;
};

#endif