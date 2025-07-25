#pragma once
#include "item.hpp"
#include "location.hpp"
#include "vector"
#include "villager.hpp"
#include "perk.hpp"
#include "Invisible_man.hpp"
#include<SFML/Graphics.hpp>
class villager;
class location;
class perk;
class item;
class monster;
class Drakula;
class programm;
class hero

{

protected:
    location *loc;
    int action;
    std::vector<item *> item_have;
    std::vector<perk *> perk_have;
   std:: string name_of_hero;

public:
    virtual void special_action(std::vector<std::vector<int>> &map,programm & bug,sf::RenderWindow & window) = 0;
    void advance(std::vector<monster *> &monsters, programm &bug);
    void guide(std::vector<std::vector<int>> &map, programm &);
    void defeat(std::vector<monster *> &monsters, programm &bug);
    void move(location *loc, programm &bug);
    int get_action();
    void set_perks(std::vector<perk *> perks);
    std::vector<perk *> &get_perks();
    void set_item(std::vector<item *> items);
    std::vector<item *> &get_items(); // refrenced too
    void pickup();
    void set_action(int);
    location *get_loc();
    std::string get_hero_name();
    hero(std::vector<perk *> &);
    void use_perk(programm &);
    void save_game(const std::string);
    void load_game( std::string,programm &bug);
    void ability(std::string);

    ~hero();
};