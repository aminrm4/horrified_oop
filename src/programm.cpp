#include "programm.hpp"
using namespace std;
#include <bits/stdc++.h>
#include "Mayor.hpp"
#include "Archaeologist.hpp"
#include <iostream>
#include "Drakula.hpp"
#include "Invisible_man.hpp"
#include "monster_card.hpp"
#include "Egyptian_Expert.hpp"
#include "form_of_the_bat.hpp"
#include "Former_Employer.hpp"
#include "Fortune_Teller.hpp"
#include "Hurried_Assistant.hpp"
#include "Hypnotic_Gaze.hpp"
#include "Sunrise.hpp"
#include "The_Innocent.hpp"
#include "Thief.hpp"
#include "The_Delivery.hpp"
#include "The_chthyologist.hpp"
#include "On_the_move.hpp"
#include "Color.hpp"
#include <stdexcept>
#include <format>
#include "TextInputBox.hpp"
#include "massage.hpp"
#include "Button2.hpp"
#include "courier.hpp"
#include "scientist.hpp"
#include "Button.hpp"

#include <algorithm>
bool programm::is_node_connected(int her, int node)
{
  vector<int> temp;
  temp = bfs(her, node);
  if (temp.size() > 2)
  {
    return false;
  }
  else
  {
    return true;
  }
}

void input_validation(string sampel)
{
  try
  {
    for (unsigned char i : sampel)
    {
      if (isdigit(i))
      {
        throw invalid_argument("be bcareful in your input\n");
      }
      if (!isalpha(i))
      {
        throw invalid_argument("be bcareful in your input\n");
      }
    }
  }
  catch (exception &e)
  {
    cerr << e.what() << endl;
    exit(0);
  }
}
void charecter_exist(string name)
{
  try
  {
    if (name != "mayor" && name != "archaeologist")
    {
      throw invalid_argument("charecter does not exist try again\n");
    }
  }
  catch (exception &e)
  {
    cerr << e.what();
    exit(0);
  }
}
void to_lowercase(std::string &s)
{
  for (char &c : s)
  {
    c = static_cast<char>(
        std::tolower(static_cast<unsigned char>(c)));
  }
}
int random_number(int min, int max)
{
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dist(min, max);
  return dist(gen);
}

void programm::clearScreen()
{
#ifdef __WIN32
  system("cls");
#else
  system("clear");
#endif
}

programm::programm()
{
  my_map.resize(maxn);
  my_map[0].push_back(2);
  my_map[2].push_back(0);

  my_map[2].push_back(9);
  my_map[9].push_back(2);

  my_map[2].push_back(1);
  my_map[1].push_back(2);

  my_map[2].push_back(6);
  my_map[6].push_back(2);

  my_map[2].push_back(5);
  my_map[5].push_back(2);

  my_map[3].push_back(4);
  my_map[4].push_back(3);

  my_map[6].push_back(5);
  my_map[5].push_back(6);

  my_map[6].push_back(9);
  my_map[9].push_back(6);

  my_map[4].push_back(5);
  my_map[5].push_back(4);

  my_map[9].push_back(5);
  my_map[5].push_back(9);

  my_map[9].push_back(8);
  my_map[8].push_back(9);

  my_map[7].push_back(8);
  my_map[8].push_back(7);

  my_map[5].push_back(10);
  my_map[10].push_back(5);

  my_map[9].push_back(10);
  my_map[10].push_back(9);

  my_map[9].push_back(18);
  my_map[18].push_back(9);

  my_map[9].push_back(14);
  my_map[14].push_back(9);

  my_map[9].push_back(13);
  my_map[13].push_back(9);

  my_map[10].push_back(11);
  my_map[11].push_back(10);

  my_map[10].push_back(15);
  my_map[15].push_back(10);

  my_map[10].push_back(13);
  my_map[13].push_back(10);

  my_map[10].push_back(14);
  my_map[14].push_back(10);

  my_map[10].push_back(18);
  my_map[18].push_back(10);

  my_map[11].push_back(16);
  my_map[16].push_back(11);

  my_map[11].push_back(12);
  my_map[12].push_back(11);

  my_map[18].push_back(17);
  my_map[17].push_back(18);

  my_map[18].push_back(14);
  my_map[14].push_back(18);

  my_map[18].push_back(13);
  my_map[13].push_back(18);

  my_map[13].push_back(14);
  my_map[14].push_back(13);

  for (int i = 0; i < 19; ++i)
  {
    int x = (i == 1 || i == 7 || i == 16 || i == 17) ? 1 : 0;
    list_of_location.push_back(new location(i, x));
  }

  list_of_items.push_back(new item(2, "flower", rgb::Color::Yellow, list_of_location[12]));
  list_of_items.push_back(new item(2, "flower", rgb::Color::Yellow, list_of_location[12]));

  list_of_items.push_back(new item(3, "tarot_deck", rgb::Color::Yellow, list_of_location[18]));
  list_of_items.push_back(new item(3, "tarot_deck", rgb::Color::Yellow, list_of_location[18]));

  list_of_items.push_back(new item(2, "garlic", rgb::Color::Yellow, list_of_location[13]));
  list_of_items.push_back(new item(2, "garlic", rgb::Color::Yellow, list_of_location[13]));

  list_of_items.push_back(new item(3, "mirrored_box", rgb::Color::Yellow, list_of_location[9]));
  list_of_items.push_back(new item(3, "mirrored_box", rgb::Color::Yellow, list_of_location[9]));

  list_of_items.push_back(new item(3, "stake", rgb::Color::Yellow, list_of_location[8]));
  list_of_items.push_back(new item(3, "stake", rgb::Color::Yellow, list_of_location[8]));

  list_of_items.push_back(new item(4, "scroll_of_thoth", rgb::Color::Yellow, list_of_location[6]));
  list_of_items.push_back(new item(4, "scroll_of_thoth", rgb::Color::Yellow, list_of_location[6]));

  list_of_items.push_back(new item(3, "violin", rgb::Color::Yellow, list_of_location[18]));
  list_of_items.push_back(new item(3, "violin", rgb::Color::Yellow, list_of_location[18]));

  list_of_items.push_back(new item(3, "tablet", rgb::Color::Yellow, list_of_location[6]));
  list_of_items.push_back(new item(3, "tablet", rgb::Color::Yellow, list_of_location[6]));

  list_of_items.push_back(new item(4, "wolfsbane", rgb::Color::Yellow, list_of_location[18]));
  list_of_items.push_back(new item(4, "wolfsbane", rgb::Color::Yellow, list_of_location[18]));

  list_of_items.push_back(new item(4, "charm", rgb::Color::Yellow, list_of_location[18]));
  list_of_items.push_back(new item(4, "charm", rgb::Color::Yellow, list_of_location[18]));

  list_of_items.push_back(new item(2, "dart", rgb::Color::Red, list_of_location[13]));
  list_of_items.push_back(new item(2, "dart", rgb::Color::Red, list_of_location[13]));

  list_of_items.push_back(new item(3, "fire_poker", rgb::Color::Red, list_of_location[9]));
  list_of_items.push_back(new item(3, "fire_poker", rgb::Color::Red, list_of_location[9]));

  list_of_items.push_back(new item(5, "rapier", rgb::Color::Red, list_of_location[10]));
  list_of_items.push_back(new item(5, "rapier", rgb::Color::Red, list_of_location[10]));

  list_of_items.push_back(new item(2, "shovel", rgb::Color::Red, list_of_location[1]));
  list_of_items.push_back(new item(2, "shovel", rgb::Color::Red, list_of_location[1]));

  list_of_items.push_back(new item(5, "torch", rgb::Color::Red, list_of_location[15]));
  list_of_items.push_back(new item(5, "torch", rgb::Color::Red, list_of_location[15]));

  list_of_items.push_back(new item(4, "pitch_fork", rgb::Color::Red, list_of_location[15]));
  list_of_items.push_back(new item(4, "pitch_fork", rgb::Color::Red, list_of_location[15]));

  list_of_items.push_back(new item(6, "rifle", rgb::Color::Red, list_of_location[15]));
  list_of_items.push_back(new item(6, "rifle", rgb::Color::Red, list_of_location[15]));

  list_of_items.push_back(new item(6, "silver_cane", rgb::Color::Red, list_of_location[5]));
  list_of_items.push_back(new item(6, "silver_cane", rgb::Color::Red, list_of_location[5]));

  list_of_items.push_back(new item(3, "knife", rgb::Color::Red, list_of_location[12]));
  list_of_items.push_back(new item(3, "knife", rgb::Color::Red, list_of_location[12]));

  list_of_items.push_back(new item(6, "pistol", rgb::Color::Red, list_of_location[14]));
  list_of_items.push_back(new item(6, "pistol", rgb::Color::Red, list_of_location[14]));

  list_of_items.push_back(new item(4, "bear_trap", rgb::Color::Red, list_of_location[5]));
  list_of_items.push_back(new item(4, "bear_trap", rgb::Color::Red, list_of_location[5]));

  list_of_items.push_back(new item(4, "speargun", rgb::Color::Red, list_of_location[3]));
  list_of_items.push_back(new item(4, "speargun", rgb::Color::Red, list_of_location[3]));

  list_of_items.push_back(new item(1, "anatomy_text", rgb::Color::Blue, list_of_location[3]));
  list_of_items.push_back(new item(1, "anatomy_text", rgb::Color::Blue, list_of_location[3]));

  list_of_items.push_back(new item(1, "centrifuge", rgb::Color::Blue, list_of_location[4]));
  list_of_items.push_back(new item(1, "centrifuge", rgb::Color::Blue, list_of_location[4]));

  list_of_items.push_back(new item(1, "kite", rgb::Color::Blue, list_of_location[11]));
  list_of_items.push_back(new item(1, "kite", rgb::Color::Blue, list_of_location[11]));

  list_of_items.push_back(new item(2, "research", rgb::Color::Blue, list_of_location[11]));
  list_of_items.push_back(new item(2, "research", rgb::Color::Blue, list_of_location[11]));

  list_of_items.push_back(new item(2, "telescope", rgb::Color::Blue, list_of_location[9]));
  list_of_items.push_back(new item(2, "telescope", rgb::Color::Blue, list_of_location[9]));

  list_of_items.push_back(new item(2, "searchlight", rgb::Color::Blue, list_of_location[14]));
  list_of_items.push_back(new item(2, "searchlight", rgb::Color::Blue, list_of_location[14]));

  list_of_items.push_back(new item(2, "experiment", rgb::Color::Blue, list_of_location[4]));
  list_of_items.push_back(new item(2, "experiment", rgb::Color::Blue, list_of_location[4]));

  list_of_items.push_back(new item(2, "analysis", rgb::Color::Blue, list_of_location[3]));
  list_of_items.push_back(new item(2, "analysis", rgb::Color::Blue, list_of_location[3]));

  list_of_items.push_back(new item(3, "rotenone", rgb::Color::Blue, list_of_location[3]));
  list_of_items.push_back(new item(3, "rotenone", rgb::Color::Blue, list_of_location[3]));

  list_of_items.push_back(new item(3, "cosmic_diffuser", rgb::Color::Blue, list_of_location[11]));
  list_of_items.push_back(new item(3, "cosmic_diffuser", rgb::Color::Blue, list_of_location[11]));

  list_of_items.push_back(new item(3, "nebularium", rgb::Color::Blue, list_of_location[11]));
  list_of_items.push_back(new item(3, "nebularium", rgb::Color::Blue, list_of_location[11]));

  list_of_items.push_back(new item(3, "monocane_mixture", rgb::Color::Blue, list_of_location[13]));
  list_of_items.push_back(new item(3, "monocane_mixture", rgb::Color::Blue, list_of_location[13]));

  list_of_items.push_back(new item(3, "fossil", rgb::Color::Blue, list_of_location[18]));
  list_of_items.push_back(new item(3, "fossil", rgb::Color::Blue, list_of_location[18]));

  list_of_perks.push_back(new visit_from_detective());
  list_of_perks.push_back(new visit_from_detective());
  list_of_perks.push_back(new visit_from_detective());
  list_of_perks.push_back(new break_of_down());
  list_of_perks.push_back(new break_of_down());
  list_of_perks.push_back(new break_of_down());
  list_of_perks.push_back(new overstock());
  list_of_perks.push_back(new overstock());
  list_of_perks.push_back(new overstock());
  list_of_perks.push_back(new overstock());
  list_of_perks.push_back(new late_into_night());
  list_of_perks.push_back(new late_into_night());
  list_of_perks.push_back(new late_into_night());
  list_of_perks.push_back(new late_into_night());
  list_of_perks.push_back(new repel());
  list_of_perks.push_back(new repel());
  list_of_perks.push_back(new repel());
  list_of_perks.push_back(new hurry());
  list_of_perks.push_back(new hurry());
  list_of_perks.push_back(new hurry());

  hero_list.push_back(new Mayor(5, list_of_location[10], list_of_perks));
  hero_list.push_back(new Archaeologist(4, list_of_location[12], list_of_perks));

  monster_list.push_back(new Drakula(4, true, 1, list_of_location[0]));
  monster_list.push_back(new invisible_man(5, false, 6, list_of_location[14]));

  monster_card_list.push_back(new form_of_the_bat(2, 2, 1));
  monster_card_list.push_back(new form_of_the_bat(2, 2, 1));
  monster_card_list.push_back(new form_of_the_bat(2, 2, 1));
  monster_card_list.push_back(new Sunrise(2, 0, 1));
  monster_card_list.push_back(new Sunrise(2, 0, 1));
  monster_card_list.push_back(new Sunrise(2, 0, 1));
  monster_card_list.push_back(new Thief(3, 2, 1));
  monster_card_list.push_back(new Thief(3, 2, 1));
  monster_card_list.push_back(new Thief(3, 2, 1));
  monster_card_list.push_back(new Thief(3, 2, 1));
  monster_card_list.push_back(new Thief(3, 2, 1));
  monster_card_list.push_back(new The_Delivery(3, 3, 1));
  monster_card_list.push_back(new Fortune_Teller(2, 3, 1));
  monster_card_list.push_back(new Former_Employer(2, 3, 1));
  monster_card_list.push_back(new Hurried_Assistant(3, 3, 2));
  monster_card_list.push_back(new The_Innocent(3, 3, 1));
  monster_card_list.push_back(new Egyptian_Expert(2, 3, 2));
  monster_card_list.push_back(new The_chthyologist(2, 3, 1));
  // monster_card_list.push_back(new Hypnotic_Gaze(2, 2, 1));
  // monster_card_list.push_back(new Hypnotic_Gaze(2, 2, 1));
  monster_card_list.push_back(new On_the_move(2, 3, 3));
  monster_card_list.push_back(new On_the_move(2, 3, 3));

  for (int i = 0; i < 12; i++)
  {

    int random = random_number(0, list_of_items.size() - 1);
    list_of_items.at(random)->get_loc()->set_item_list(list_of_items.at(random));
    list_of_items.erase(list_of_items.begin() + random);
  }
  for (auto i : monster_list)
  {
    i->get_loc()->set_monster_list(i);
  }
  for (auto i : hero_list)
  {
    i->get_loc()->set_hero_list(i);
  }
}
std::vector<int> programm::bfs(int s, int t)
{
  bool vis[maxn];
  int par[maxn];
  int dis[maxn];
  fill(dis, dis + 20, -1);
  fill(vis, vis + 20, false);
  fill(par, par + 20, -1);
  queue<int> q;
  q.push(s);
  vis[s] = true;
  dis[s] = 0;
  bool found = false;
  while (!q.empty() && !found)
  {
    int u = q.front();
    q.pop();
    for (int v : my_map[u])
    {
      if (!vis[v])
      {
        vis[v] = true;
        par[v] = u;
        dis[v] = dis[u] + 1;
        if (v == t)
        {
          found = true;
          break;
        }
        q.push(v);
      }
    }
  }

  if (!vis[t])
  {
    throw invalid_argument("the path does not exist\n");
  }
  else
  {
    vector<int> path;
    for (int v = t; v != -1; v = par[v])
      path.push_back(v);
    reverse(path.begin(), path.end());

    return path;
  }
}
int programm::get_night_terror()
{
  return night_terror;
}
void programm::set_night_terror(int value)
{
  night_terror = value;
  if (night_terror == 5)
  {
    cout << "the night terror level reached 5 \n";
    cin.get();
    this->clearScreen();
    cout << "Game over ";
    exit(0);
  }
}
void programm::next_frenzy()
{

  if (monster_list.size() != 1)
  {

    if (monster_list[0]->get_is_frenzy() == false && monster_list[1]->get_is_frenzy() == false)
    {
      if (monster_list[0]->get_frenzy_order() > monster_list[1]->get_frenzy_order())
      {
        monster_list[0]->set_is_frenzy(true);
      }
      else
      {
        monster_list[1]->set_is_frenzy(true);
      }
    }
    else
    {
      if (monster_list[0]->get_is_frenzy())
      {
        monster_list[1]->set_is_frenzy(true);
        monster_list[0]->set_is_frenzy(false);
      }
      else
      {
        monster_list[0]->set_is_frenzy(true);
        monster_list[1]->set_is_frenzy(false);
      }
    }
  }
  else
  {
    monster_list[0]->set_is_frenzy(true);
  }
}
string programm::show_all_item(const vector<item *> &show, LocationInfo &state)
{

  state.items = "";
  unordered_map<string, int> same_element;

  if (show.empty())
    return state.items;

  for (auto i : show)
  {
    if (i != nullptr)
    {
      if (i->get_Color() == rgb::Color::Red)
      {
        same_element[to_string(i->get_power()) + ' ' + "red" + ' ' + i->get_name()]++;
      }
      if (i->get_Color() == rgb::Color::Yellow)
      {
        same_element[to_string(i->get_power()) + ' ' + "yellow" + ' ' + i->get_name()]++;
      }
      if (i->get_Color() == rgb::Color::Blue)
      {
        same_element[to_string(i->get_power()) + ' ' + "blue" + ' ' + i->get_name()]++;
      }
    }
  }

  for (const auto &i : same_element)
  {
    state.items = state.items + ' ' + (i.first + '(' + to_string(i.second) + ')');
  }

  return state.items;
}

string programm::show_all_item_of_hero(const vector<item *> show)
{
  string temp = "";
  map<string, int> same_element;
  for (auto i : show)
  {
    if (i != nullptr)
    {
      if (i->get_Color() == rgb::Color::Red)
      {
        same_element[to_string(i->get_power()) + ' ' + "red" + ' ' + i->get_name()]++;
      }
      if (i->get_Color() == rgb::Color::Yellow)
      {
        same_element[to_string(i->get_power()) + ' ' + "yellow" + ' ' + i->get_name()]++;
      }
      if (i->get_Color() == rgb::Color::Blue)
      {
        same_element[to_string(i->get_power()) + ' ' + "blue" + ' ' + i->get_name()]++;
      }
    }
  }

  for (const auto &i : same_element)
  {
    temp = temp + " " + i.first + "(" + to_string(i.second) + ")";
  }
  return temp;
}

perk *programm::set_award(int index)
{
  return list_of_perks[index];
}
string programm::show_all_villager(const vector<villager *> &show, LocationInfo &state)
{

  state.villagers = "";
  unordered_map<string, int> same_element;

  if (show.empty())
    return state.villagers;

  for (auto i : show)
  {
    if (i != nullptr)
    {

      same_element[i->get_name()]++;
    }
  }

  for (const auto &i : same_element)
  {
    state.villagers = state.villagers + ' ' + (i.first + '(' + to_string(i.second) + ')');
  }

  return state.villagers;
}
string programm::show_all_hero(const vector<hero *> &show, LocationInfo &state)
{

  state.hero = "";
  unordered_map<string, int> same_element;

  if (show.empty())
    return state.hero;

  for (auto i : show)
  {

    if (i != nullptr)
    {

      same_element[i->get_hero_name()]++;
    }
  }

  for (const auto &i : same_element)
  {
    state.hero = state.hero + ' ' + (i.first + '(' + to_string(i.second) + ')');
  }

  return state.hero;
}
string programm::show_all_mosnter(const vector<monster *> &show, LocationInfo &state)
{

  state.monsters = "";
  unordered_map<string, int> same_element;

  if (show.empty())
    return state.monsters;

  for (auto i : show)
  {
    if (i != nullptr)
    {

      same_element[i->get_mons_name()]++;
    }
  }

  for (const auto &i : same_element)
  {
    state.monsters = state.monsters + ' ' + (i.first + '(' + to_string(i.second) + ')');
  }

  return state.monsters;
}

template <typename T>
string programm::show_hero_deatail(T vec)
{

  string temp = "";
  map<string, int> same_element;
  for (const auto &i : vec)
  {
    ++same_element[i->get_name()];
  }

  for (const auto &i : same_element)
  {
    temp = temp + " " + i.first + "(" + to_string(i.second) + ")";
  }
  return temp;
}
void programm::terminal_handler(LocationInfo &info, string &first_enter, string &secend_enter)
{
  int enter_count = 0;
  std::string terror_text = "night terror level : " + to_string(get_night_terror());
  static constexpr const char *map_template = R"MAP(
|{0:^87}|
|                                                                                       |
|                      hospital(0)     grave_yard(1)                                    |
|                                \      /                                               |
|                               church(2)___________                                    |
|                                  |    \           \                                   |
|                                  |     museum(6)  |                                   |
|                                  |    /     |     |                                   |
|                                  |   /      |     |                                   |
|                                  |  /       |     |                                   |
|               laboratory(4)────shop(5)─────mansion(9)────abbey(8)────cryptt(7)        |
|                    /            │             |                                       |
|                   /             |   __________|_____________________                  |
|           institute(3)          │  /          |          \          \                 |
|                           theatre(10)  precinct(14)  inn(13)    camp(18)────cave(17)  |
|                            /       \                                                  |
|                     barn(15)    __tower(11)                                           |
|                                |       \                                              |
|                                │      docks(12)                                       |
|                           dungeon(16)                                                 |
)MAP";

  std::string map_ascii = std::format(map_template, terror_text);
  map<string, LocationInfo> location_data = {
      {"0 ) Hospital", {show_all_item(list_of_location[0]->get_item_list(), info), show_all_mosnter(list_of_location[0]->get_monster_list(), info), show_all_villager(list_of_location[0]->get_villager_list(), info), show_all_hero(list_of_location[0]->get_hero_list(), info), to_string(list_of_location[0]->get_coffin_exist())

                       }},

      {"1 ) grave_yard", {show_all_item(list_of_location[1]->get_item_list(), info), show_all_mosnter(list_of_location[1]->get_monster_list(), info), show_all_villager(list_of_location[1]->get_villager_list(), info), show_all_hero(list_of_location[1]->get_hero_list(), info), to_string(list_of_location[1]->get_coffin_exist())

                         }},

      {"2 ) church",
       {show_all_item(list_of_location[2]->get_item_list(), info),
        show_all_mosnter(list_of_location[2]->get_monster_list(), info),
        show_all_villager(list_of_location[2]->get_villager_list(), info),
        show_all_hero(list_of_location[2]->get_hero_list(), info),
        to_string(list_of_location[2]->get_coffin_exist())}},

      {"3 ) institute",
       {show_all_item(list_of_location[3]->get_item_list(), info),
        show_all_mosnter(list_of_location[3]->get_monster_list(), info),
        show_all_villager(list_of_location[3]->get_villager_list(), info),
        show_all_hero(list_of_location[3]->get_hero_list(), info),
        to_string(list_of_location[3]->get_coffin_exist())

       }},

      {"4 ) Lab",
       {show_all_item(list_of_location[4]->get_item_list(), info),
        show_all_mosnter(list_of_location[4]->get_monster_list(), info),
        show_all_villager(list_of_location[4]->get_villager_list(), info),
        show_all_hero(list_of_location[4]->get_hero_list(), info),
        to_string(list_of_location[4]->get_coffin_exist())

       }},
      {"5 ) shop",
       {show_all_item(list_of_location[5]->get_item_list(), info),
        show_all_mosnter(list_of_location[5]->get_monster_list(), info),
        show_all_villager(list_of_location[5]->get_villager_list(), info),
        show_all_hero(list_of_location[5]->get_hero_list(), info),
        to_string(list_of_location[5]->get_coffin_exist())

       }},

      {"6 ) museum",
       {show_all_item(list_of_location[6]->get_item_list(), info),
        show_all_mosnter(list_of_location[6]->get_monster_list(), info),
        show_all_villager(list_of_location[6]->get_villager_list(), info),
        show_all_hero(list_of_location[6]->get_hero_list(), info),
        to_string(list_of_location[6]->get_coffin_exist())

       }},
      {"7 ) cryptt",
       {show_all_item(list_of_location[7]->get_item_list(), info),
        show_all_mosnter(list_of_location[7]->get_monster_list(), info),
        show_all_villager(list_of_location[7]->get_villager_list(), info),
        show_all_hero(list_of_location[7]->get_hero_list(), info),
        to_string(list_of_location[7]->get_coffin_exist())

       }},

      {"8 ) abbey",
       {show_all_item(list_of_location[8]->get_item_list(), info),
        show_all_mosnter(list_of_location[8]->get_monster_list(), info),
        show_all_villager(list_of_location[8]->get_villager_list(), info),
        show_all_hero(list_of_location[8]->get_hero_list(), info),
        to_string(list_of_location[8]->get_coffin_exist())

       }},

      {"9 ) Mansion",
       {show_all_item(list_of_location[9]->get_item_list(), info),
        show_all_mosnter(list_of_location[9]->get_monster_list(), info),
        show_all_villager(list_of_location[9]->get_villager_list(), info),
        show_all_hero(list_of_location[9]->get_hero_list(), info),
        to_string(list_of_location[9]->get_coffin_exist())

       }},
      {"10 ) theatre",
       {show_all_item(list_of_location[10]->get_item_list(), info),
        show_all_mosnter(list_of_location[10]->get_monster_list(), info),
        show_all_villager(list_of_location[10]->get_villager_list(), info),
        show_all_hero(list_of_location[10]->get_hero_list(), info),
        to_string(list_of_location[10]->get_coffin_exist())

       }},
      {"11 ) tower",
       {show_all_item(list_of_location[11]->get_item_list(), info),
        show_all_mosnter(list_of_location[11]->get_monster_list(), info),
        show_all_villager(list_of_location[11]->get_villager_list(), info),
        show_all_hero(list_of_location[11]->get_hero_list(), info),
        to_string(list_of_location[11]->get_coffin_exist())

       }},
      {"12 ) docks",
       {show_all_item(list_of_location[12]->get_item_list(), info),
        show_all_mosnter(list_of_location[12]->get_monster_list(), info),
        show_all_villager(list_of_location[12]->get_villager_list(), info),
        show_all_hero(list_of_location[12]->get_hero_list(), info),
        to_string(list_of_location[12]->get_coffin_exist())

       }},
      {"13 ) inn",
       {show_all_item(list_of_location[13]->get_item_list(), info),
        show_all_mosnter(list_of_location[13]->get_monster_list(), info),
        show_all_villager(list_of_location[13]->get_villager_list(), info),
        show_all_hero(list_of_location[13]->get_hero_list(), info),
        to_string(list_of_location[13]->get_coffin_exist())

       }},
      {"14 ) precinct",
       {show_all_item(list_of_location[14]->get_item_list(), info),
        show_all_mosnter(list_of_location[14]->get_monster_list(), info),
        show_all_villager(list_of_location[14]->get_villager_list(), info),
        show_all_hero(list_of_location[14]->get_hero_list(), info),
        to_string(list_of_location[14]->get_coffin_exist())

       }},
      {"15 ) barn",
       {show_all_item(list_of_location[15]->get_item_list(), info),
        show_all_mosnter(list_of_location[15]->get_monster_list(), info),
        show_all_villager(list_of_location[15]->get_villager_list(), info),
        show_all_hero(list_of_location[15]->get_hero_list(), info),
        to_string(list_of_location[15]->get_coffin_exist())

       }},
      {"16 ) dungeon",
       {show_all_item(list_of_location[16]->get_item_list(), info),
        show_all_mosnter(list_of_location[16]->get_monster_list(), info),
        show_all_villager(list_of_location[16]->get_villager_list(), info),
        show_all_hero(list_of_location[16]->get_hero_list(), info),
        to_string(list_of_location[16]->get_coffin_exist())

       }},

      {"17 ) cave",
       {show_all_item(list_of_location[17]->get_item_list(), info),
        show_all_mosnter(list_of_location[17]->get_monster_list(), info),
        show_all_villager(list_of_location[17]->get_villager_list(), info),
        show_all_hero(list_of_location[17]->get_hero_list(), info),
        to_string(list_of_location[17]->get_coffin_exist())

       }},

      {"18 ) camp",
       {show_all_item(list_of_location[18]->get_item_list(), info),
        show_all_mosnter(list_of_location[18]->get_monster_list(), info),
        show_all_villager(list_of_location[18]->get_villager_list(), info),
        show_all_hero(list_of_location[18]->get_hero_list(), info),
        to_string(list_of_location[18]->get_coffin_exist())

       }}};
  map<string, string> action_help = {
      {"Move", "Move to another location."},
      {"Guide", "move the villager one step to the hero,or move a villager to the neighbor house base on the hero location"},
      {"Pick Up", "can pick up desired items"},
      {"Advance", "can improve the task for defeating a monster."},
      {"Defeat", "kill a monster when all taks has been done(should be in the same place with mosnter)"},
      {"special action", "use it for archzeologist to pick up the items in the  neighbor locations"},
      {"Quit", "Exit the game.(your data will be lost)"},
      {"use perk", "use the perk wich hero have(from hero panel)"}};

  map<string, string> heros_data = {

      {"hero name ", hero_list[0]->get_hero_name()},
      {"item have ", show_all_item_of_hero(hero_list[0]->get_items())},
      {"perk have ", show_hero_deatail(hero_list[0]->get_perks())},
      {"action left ", to_string(hero_list[0]->get_action())}

  };

  map<string, string> secend_heros_data = {
      {"hero name ", hero_list[1]->get_hero_name()},
      {"item have ", show_all_item_of_hero(hero_list[1]->get_items())},
      {"perk have ", show_hero_deatail(hero_list[1]->get_perks())},
      {"action left ", to_string(hero_list[1]->get_action())}

  };
  map<string, string> monster_data = {
      {monster_list[0]->get_mons_name(), " task remain :" + to_string(monster_list[0]->get_hidden_item())},
      {monster_list[1]->get_mons_name(), " task remain :" + to_string(monster_list[1]->get_hidden_item())}};

  bool show_loc = false;
  bool show_hero = false;
  bool show_act = false;
  bool show_hero1 = false;
  bool show_map = false;
  bool show_task = false;
  int sel_loc = 0, sel_act = 0;
  int sel_hero = 0;
  int sel_hero1 = 0;
  int sel_map = 0;
  int sel_taks = 0;
  vector<string> actions = {"Move", "Guide", "Pick Up", "Advance", "Defeat", "special action ", "Quit", "use perk"};
  vector<string> heros = {"hero name ", "item have ", "perk have ", "action left "};
  vector<string> heros1 = {"hero name ", "item have ", "perk have ", "action left "};
  vector<string> monster_task = {monster_list[0]->get_mons_name(), monster_list[1]->get_mons_name()};
  vector<string> locations = {"0 ) Hospital", "1 ) grave_yard", "2 ) church", "3 ) institute", "4 ) Lab", "5 ) shop", "6 ) museum", "7 ) cryptt", "8 ) abbey", "9 ) Mansion", "10 ) theatre", "11 ) tower", "12 ) docks", "13 ) inn", "14 ) precinct", "15 ) barn", "16 ) dungeon", "17 ) cave", "18 ) camp"};
}
programm::~programm()
{
  for (auto item : list_of_items)
  {
    delete item;
  }
  for (auto location : list_of_location)
  {
    delete location;
  }
  for (auto perk : list_of_perks)
  {
    delete perk;
  }
  for (auto hero : hero_list)
  {
    delete hero;
  }
  for (auto monster : monster_list)
  {
    delete monster;
  }
  for (auto monster_card : monster_card_list)
  {
    delete monster_card;
  }

  monster_card_list.clear();
  monster_list.clear();
  hero_list.clear();
  list_of_perks.clear();
  list_of_location.clear();
  list_of_items.clear();
}
void drawheroimage()
{
}
bool isNumeric(const std::string &str)
{
  return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}
void programm::run()
{
  vector<pair<string, int>> usersinfo(2);
  enum initstate
  {
    infopage,
    heroSelection1,
    heroSelection2,
    exit,
    playmenu
  };
  initstate state = initstate::infopage;
  sf::RenderWindow window({1920, 1080}, "Horrified board game"); // starting the game , getting name of players ...
  window.setFramerateLimit(60);
  sf::Texture map_texture;
  sf::Sprite map_sprite;

  sf::Texture bgt;
  sf::Sprite bg;
  if (!bgt.loadFromFile("../Horrified_Assets/bg4.png"))
  {
    throw out_of_range("coudnt find the bg asset \n");
  }
  bg.setTexture(bgt);
  bg.setScale({1920.f / bgt.getSize().x, 1080.f / bgt.getSize().y});
  Button next({200, 100}, {1920 - 400, 1080 - 200}, "Next");
  Button back({200, 100}, {1920 - 200, 1080 - 100}, "Back");

  massage massage1({(1920.f / 2) - (500.f / 2), 100.f}, "Player one please enter your information", sf::Color::Red, 32);
  massage massage2({(1920.f / 2) - (500.f / 2), 600.f}, "Player two please enter your information", sf::Color::Red, 32);

  TextInputBox playerName1({(1920.f / 2) - (500.f / 2), 200.f}, {500.f, 50.f});
  TextInputBox playerGarlic1({(1920.f / 2) - (500.f / 2), 300.f}, {500.f, 50.f});

  TextInputBox playerName2({(1920.f / 2) - (500.f / 2), 700.f}, {500.f, 50.f});
  TextInputBox playerGarlic2({(1920.f / 2) - (500.f / 2), 800.f}, {500.f, 50.f}); // info page end

  if (!map_texture.loadFromFile("../Horrified_Assets/map.png")) // play menu
  {
    throw out_of_range("coudnt find the map asset \n");
  }
  map_sprite.setTexture(map_texture);
  sf::Vector2u textureSize = map_texture.getSize();
  float scaleX = 1080.0f / textureSize.x;
  float scaleY = 1030.0f / textureSize.y;
  map_sprite.setScale(scaleX, scaleY);
  sf::Vector2f map_origin = map_sprite.getOrigin();
  map_sprite.setPosition({(1920 - 1080) / 2, 0}); // rendering map in mid
  sf::Vector2f button = {200.f, 50.f};
  Button move(button, {50.f, 400.f}, "Move");
  Button ability(button, {50.f, move.getPosButton().y + 75}, "Ability");
  Button defeat(button, {50.f, ability.getPosButton().y + 75}, "Defeat");
  Button advance(button, {50.f, defeat.getPosButton().y + 75}, "advance");
  Button pickup(button, {50.f, advance.getPosButton().y + 75}, "pick up");
  Button guide(button, {50.f, pickup.getPosButton().y + 75}, "Guide");
  Button items(button , {50.f, guide.getPosButton().y + 75} , "items");
  Button perks(button , {50.f, items.getPosButton().y + 75} , "perks");

  if (!map_texture.loadFromFile("../Horrified_Assets/map.png"))
  {
    throw out_of_range("coudnt find the map asset \n");
  }
  vector<Button2> B;
  Button2 Mayor(Button2({225, 300}, {0, 0}, "../Horrified_Assets/Heros/Mayor.png"));
  Button2 Archaeologist(Button2({225, 300}, {225, 0}, "../Horrified_Assets/Heros/Archaeologist.png"));
  Button2 courier(Button2({225, 300}, {450, 0}, "../Horrified_Assets/Heros/Courier.png"));
  Button2 scientist(Button2({225, 300}, {675, 0}, "../Horrified_Assets/Heros/Scientist.png"));

  vector<int> Nohero;
  int heroNo = 0;
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {

      if (state == initstate::playmenu)
      {
        if (hero_list[heroNo]->get_action() <= 0)
        {

          int rand = 0;
          rand = random_number(0, static_cast<int>(monster_card_list.size()) - 1);
          cout << rand << endl;
          monster_card_list[rand]->item_handler(*this);
          monster_card_list[rand]->event(my_map, list_of_location, *this);
          monster_card_list[rand]->monster_strike(*this, monster_list);
          delete monster_card_list[rand];
          monster_card_list.erase(monster_card_list.begin() + rand);
          if (monster_card_list.empty())
          {
            cout << "you lose the game " << endl;
            // exit(0);
          }
          if(typeid(*hero_list[heroNo]).name() == typeid(class Mayor).name())
          {
            hero_list[heroNo]->set_action(5);
          }
          else
          hero_list[heroNo]->set_action(4);

          if (heroNo == 1)
            heroNo = 0;
          else
            heroNo = 1;
          
        }
        if (move.isClicked(event, window))
        {

        }
        if (ability.isClicked(event, window))
        {
        }
        if (defeat.isClicked(event, window))
        {
        }
        if (advance.isClicked(event, window))
        {
        }
        if (pickup.isClicked(event, window))
        {
        }
        if (guide.isClicked(event, window))
        {
        }
      }

      if (state == initstate::heroSelection1)
      {
        if (Mayor.isClicked(event, window) && !Mayor.get_status())
        {
          Nohero.push_back(0);
          state = initstate::heroSelection2;
          Mayor.set_status(!Mayor.get_status());
        }
        if (Archaeologist.isClicked(event, window) && !Archaeologist.get_status())
        {
          Nohero.push_back(1);
          state = initstate::heroSelection2;
          Archaeologist.set_status(!Archaeologist.get_status());
        }
        if (courier.isClicked(event, window) && !courier.get_status())
        {
          Nohero.push_back(2);
          state = initstate::heroSelection2;
          courier.set_status(!courier.get_status());
        }
        if (scientist.isClicked(event, window) && !scientist.get_status())
        {
          Nohero.push_back(3);
          state = initstate::heroSelection2;
          scientist.set_status(!scientist.get_status());
        }
      }
      if (state == initstate::heroSelection2)
      {
        if (Mayor.isClicked(event, window) && !Mayor.get_status())
        {
          Nohero.push_back(0);
          state = initstate::playmenu;
          Mayor.set_status(!Mayor.get_status());
        }
        if (Archaeologist.isClicked(event, window) && !Archaeologist.get_status())
        {
          Nohero.push_back(1);
          state = initstate::playmenu;
          Archaeologist.set_status(!Archaeologist.get_status());
        }
                if (courier.isClicked(event, window) && !courier.get_status())
        {
          Nohero.push_back(2);
          state = initstate::playmenu;
          courier.set_status(!courier.get_status());
        }
        if (scientist.isClicked(event, window) && !scientist.get_status())
        {
          Nohero.push_back(3);
          state = initstate::playmenu;
          scientist.set_status(!scientist.get_status());
        }
      }

      if (event.type == sf::Event::Closed)
        window.close();

      if (state == initstate::infopage)
      {
        if (next.isClicked(event, window) && isNumeric(playerGarlic1.getInput()) && isNumeric(playerGarlic2.getInput()))
        {
          state = initstate::heroSelection1;
        }

        playerName1.handleEvent(event, window);
        playerName2.handleEvent(event, window);
        usersinfo[0].first = playerName1.getInput();
        usersinfo[1].first = playerName2.getInput();

        playerGarlic1.handleEvent(event, window);
        playerGarlic2.handleEvent(event, window);
        if (isNumeric(playerGarlic1.getInput()) && isNumeric(playerGarlic2.getInput()))
        {
          usersinfo[0].second = stoi(playerGarlic1.getInput());
          usersinfo[1].second = stoi(playerGarlic2.getInput());
          sort(usersinfo.begin(), usersinfo.end(), [](pair<string, int> &a, pair<string, int> &b)
               { return a.second > b.second; });
        }
      }
    }

    window.clear();
    window.draw(bg);
    if(state == initstate::heroSelection1 || state == initstate::heroSelection2)
    {
      Mayor.draw(window);
      Archaeologist.draw(window);
      courier.draw(window);
      scientist.draw(window);
    }
    if (state == initstate::playmenu)
    {
      items.draw(window);
      perks.draw(window);
      move.draw(window);
      ability.draw(window);
      defeat.draw(window);
      advance.draw(window);
      window.draw(map_sprite);
      pickup.draw(window);
      guide.draw(window);

      if (typeid(*hero_list[heroNo]).name() == typeid(class Mayor).name())
      {
        Mayor.draw(window);
      }
      else
      {
        Archaeologist.draw(window);
      }
    }
    if (state == initstate::infopage)
    {
      if (!isNumeric(playerGarlic1.getInput()))
      {
        massage Error({playerGarlic1.getPos().x + 500, playerGarlic1.getPos().y + 50}, "Please Enter only in digits", sf::Color::Red, 15);
        Error.draw(window);
      }
      if (!isNumeric(playerGarlic2.getInput()))
      {
        massage Error({playerGarlic2.getPos().x + 500, playerGarlic2.getPos().y + 50}, "Please Enter only in digits", sf::Color::Red, 15);
        Error.draw(window);
      }
      next.draw(window);
      massage1.draw(window);
      playerName1.draw(window, "Enter your name");
      playerGarlic1.draw(window, "last time you ate a garlic");
      massage2.draw(window);
      playerName2.draw(window, "Enter your name");
      playerGarlic2.draw(window, "last time you ate a garlic");
    }
    window.display();
  }

  for (auto &&hero : usersinfo)
  {
  }

  return;
}
