#pragma once
#include "hero.hpp"
#include "monster.hpp"
#include "item.hpp"
#include "location.hpp"
#include <bits/stdc++.h>
#include "perk.hpp"
class break_of_down : public perk
{
public:
    void play(hero * he, std::vector<hero *> he_list, monster * mo,std:: vector<location *> loc, std::vector<item *>it_list, std::vector<monster *>mo_list, std::vector<std::vector<int>>road) override final;
    break_of_down() = default;
    ~break_of_down() = default;
};