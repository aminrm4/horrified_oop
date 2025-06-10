#ifndef LATE_INTO_NIGHT_HPP
#define LATE_INTO_NIGHT_HPP
#include "hero.hpp"
#include "monster.hpp"
#include "item.hpp"
#include "location.hpp"
#include <bits/stdc++.h>
#include "perk.hpp"
class late_into_night : public perk
{
public:
    void play(hero *, std::vector<hero *>, monster *, location *, std::vector<item *>, std::vector<monster *>, std::vector<std::vector<int>>) override final;
    late_into_night()=default;
    ~late_into_night()=default;
};

#endif