#pragma once
#include <iostream>
#include <bits/stdc++.h>
#include "item.hpp"
#include "perk.hpp"
#include "location.hpp"
#include "map1.hpp"
#include "monster_card.hpp"
#include "monster.hpp"
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
struct LocationInfo
{
  string items;
  string monsters;
  string villagers;
  string hero;
};
class programm
{
public:
  static constexpr int maxn = 19;
  static int night_terror;
  std::vector<location *> list_of_location;
  std::vector<item *> list_of_items;
  std::vector<perk *> list_of_perks;
  std::vector<std::vector<int>> my_map;
  std::vector<monster *> monster_list;
  std::vector<monster_card *> monster_card_list;
  vector<monster*>monster_list;
  vector<hero *>hero_list;

public:
  perk *set_award(int); // make the data member private and have to add this function
  void next_frenzy();
  std::set<int> random_generator(int start, int end, int count);
  std::vector<int> bfs(int s, int t);
  static int get_night_terror();
  static void set_night_terror(int);
  programm();
  bool check_terro_night();
  void run();
  void terminal_handler(LocationInfo &info,string &,string &);
  string show_all_item(const vector<item *> &show, LocationInfo &);
  string show_all_villager(const vector<villager *> &, LocationInfo &);
  string show_all_hero(const vector<hero *> &, LocationInfo &);
  string show_all_mosnter(const vector<monster *> &, LocationInfo &);
  template<typename T>
  string show_hero_deatail(T);
   void clearScreen();
};
