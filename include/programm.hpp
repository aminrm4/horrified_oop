#pragma once
#include <iostream>
#include <bits/stdc++.h>
#include "item.hpp"
#include "perk.hpp"
#include "location.hpp"
#include "map1.hpp"
#include "monster.hpp"
#include "visit_from_detective.hpp"
#include "repel.hpp"
#include "hurry.hpp"
#include "late_into_night.hpp"
#include "break_of_down.hpp"
#include "overstock.hpp"
#include <Color.hpp>
using namespace std;
class monster_card;
class villager;
class programm
{
public:
  static constexpr int maxn = 19;
  int night_terror = 0;
  std::vector<location *> list_of_location;
  std::vector<item *> list_of_items;
  std::vector<perk *> list_of_perks;
  std::vector<std::vector<int>> my_map;
  std::vector<monster *> monster_list;
  std::vector<monster_card *> monster_card_list;
  vector<hero *> hero_list;

public:
  perk *set_award(int);
  void next_frenzy();
  std::vector<int> bfs(int s, int t);
  int get_night_terror();
  void set_night_terror(int);
  bool check_terro_night();
  void run(bool);
  programm();
  ~programm();
  void save_game(const std::string file_name);
  void load_game(std::string);
};
