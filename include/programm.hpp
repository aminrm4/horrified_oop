#pragma once
#include <iostream>
#include <bits/stdc++.h>
//#include "item.hpp"
//#include "perk.hpp"
//#include "location.hpp"
class programm
{
public:
    static constexpr int maxn = 19;
    std::set<int> random_generator(int start, int end, int count);
    //std::vector<location *> list_of_location;
   // std::vector<item *> list_of_items;
    //std::vector<perk *> list_of_perks;
    std::vector<std::vector<int>> my_map;
    std::vector<int> bfs(int s, int t);
    programm();
};