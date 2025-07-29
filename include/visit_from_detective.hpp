#ifndef VISIT_FROM_DETECTIVE_HPP
#define VISIT_FROM_DETECTIVE_HPP
#include "hero.hpp"
#include "monster.hpp"
#include "item.hpp"
#include "location.hpp"
#include <bits/stdc++.h>
#include "perk.hpp"
#include<SFML/Graphics.hpp>
class programm;
class visit_from_detective : public perk
{
public:
    void play(programm &help_obj1,sf::RenderWindow & window,hero * her=nullptr) override final;

    visit_from_detective();
    ~visit_from_detective() = default;
};

#endif