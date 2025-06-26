#ifndef VISIT_FROM_DETECTIVE_HPP
#define VISIT_FROM_DETECTIVE_HPP
#include "hero.hpp"
#include "monster.hpp"
#include "item.hpp"
#include "location.hpp"
#include <bits/stdc++.h>
#include "perk.hpp"
class programm;
class visit_from_detective:public perk
{
public:
    void play(hero *he, std::vector<hero *> & he_list, monster *mo, std::vector<location *> & loc, std::vector<item *> & it_list, std::vector<monster *>  & mo_list, programm  & help_obj1) override final;

    visit_from_detective()=default;
    ~visit_from_detective()=default;

};


#endif