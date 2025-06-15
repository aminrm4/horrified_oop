#pragma once
#include <iostream>
#include <bits/stdc++.h>
#include "item.hpp"
#include "perk.hpp"
#include "location.hpp"
#include "map1.hpp"
#include"monster_card.hpp"
#include"monster.hpp"
class programm
{
private:
    static constexpr int maxn = 19;
    static int night_terror;
    std::vector<location *> list_of_location;
    std::vector<item *> list_of_items;
    std::vector<perk *> list_of_perks;
    std::vector<std::vector<int>> my_map;
    std::vector<monster *>monster_list;
    std::vector<monster_card *>monster_card_list;
    public:
perk* set_award(int);//make the data member private and have to add this function
    void next_frenzy();
std::set<int> random_generator(int start, int end, int count);
    std::vector<int> bfs(int s, int t);
    static int get_night_terror();
    static void set_night_terror(int);
    programm();
    bool check_terro_night();
};
