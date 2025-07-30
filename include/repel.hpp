#pragma once
#include "hero.hpp"
#include "monster.hpp"
#include "item.hpp"
#include "location.hpp"
#include <bits/stdc++.h>
#include "perk.hpp"
#include<SFML/Graphics.hpp>
class repel : public perk
{
public:
     void play(programm &help_obj1,sf::RenderWindow & window,hero * her=nullptr) override final;

     repel();
     ~repel() = default;
};