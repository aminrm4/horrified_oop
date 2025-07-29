#pragma once
#include "hero.hpp"
#include "monster.hpp"
#include "item.hpp"
#include "location.hpp"
#include <bits/stdc++.h>
#include "perk.hpp"
#include<SFML/Graphics.hpp>
class break_of_down : public perk
{
public:
    void play(programm &help_obj1,sf::RenderWindow & window) override final;
    break_of_down();
    ~break_of_down() = default;
};