#ifndef LATE_INTO_NIGHT_HPP
#define LATE_INTO_NIGHT_HPP
#include "hero.hpp"
#include "monster.hpp"
#include "item.hpp"
#include "location.hpp"
#include <bits/stdc++.h>
#include "perk.hpp"
#include"programm.hpp"
class late_into_night : public perk
{
public:
    void play(hero *he, std::vector<hero *> &he_list, monster *mo, std::vector<location *>& loc, std::vector<item *> &it_list, std::vector<monster *> &mo_list, programm &help_obj1) override final;
    late_into_night()=default;
    ~late_into_night()=default;
};

#endif