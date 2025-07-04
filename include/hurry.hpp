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
    void play(programm &help_obj1) override final;
    hurry();
    ~hurry() = default;
};

#endif