#ifndef VISIT_FROM_DETECTIVE_HPP
#define VISIT_FROM_DETECTIVE_HPP
#include "hero.hpp"
#include "monster.hpp"
#include "item.hpp"
#include "location.hpp"
#include <bits/stdc++.h>
#include "perk.hpp"
class visit_from_detective:public perk
{
public:
    void play(hero *, std::vector<hero *>, monster *, location *, std::vector<item *>, std::vector<monster *>, std::vector<std::vector<int>>) override final;

    visit_from_detective()=default;
    ~visit_from_detective()=default;

};


#endif