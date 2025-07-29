#ifndef PERK_HPP
#define PERK_HPP
#include "hero.hpp"
#include "monster.hpp"
#include "location.hpp"
#include <bits/stdc++.h>
#include<SFML/Graphics.hpp>
class item;
class programm;
class perk
{
public:
    std::string name;
    std::string get_name();
    virtual void play(programm &help_obj1,sf::RenderWindow & window) = 0;
    perk() = default;
    virtual ~perk() = default;
    void save_game(const std::string);
    void load_game(std::string,programm &);
};

#endif