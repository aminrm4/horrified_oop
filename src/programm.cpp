#include "programm.hpp"
using namespace std;
using namespace ftxui;
#include <bits/stdc++.h>
#include "Mayor.hpp"
#include "Archaeologist.hpp"
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/screen/color_info.hpp>
#include <ftxui/dom/elements.hpp>
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
bool programm::check_terro_night()
{
  if (night_terror >= 5)
  {
    return false;
  }
  else
  {
    return true;
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
  auto screen = ScreenInteractive::TerminalOutput();
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
map<string, string> monster_data;
  for (auto mon : monster_list)
  {
    monster_data[mon->get_mons_name()] = " task remain :" + to_string(mon->get_hidden_item());
  }

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
  //vector<string> monster_task = {monster_list[0]->get_mons_name(), monster_list[1]->get_mons_name()};
  vector<string> locations = {"0 ) Hospital", "1 ) grave_yard", "2 ) church", "3 ) institute", "4 ) Lab", "5 ) shop", "6 ) museum", "7 ) cryptt", "8 ) abbey", "9 ) Mansion", "10 ) theatre", "11 ) tower", "12 ) docks", "13 ) inn", "14 ) precinct", "15 ) barn", "16 ) dungeon", "17 ) cave", "18 ) camp"};

  auto loc_menu = Radiobox(&locations, &sel_loc);
  auto act_menu = Radiobox(&actions, &sel_act);
  auto hero_menu = Radiobox(&heros, &sel_hero);
  auto heros1_menu = Radiobox(&heros1, &sel_hero1);
  //auto taks_menu = Radiobox(&monster_task, &sel_taks);
  Component renderer = Renderer([&]
                                {
    Elements elements;
    
    elements.push_back(paragraph("Press L:Location, H:Hero,  J: secend Hero , M :show map , A:Action , T:monster_taks, Use arrows+Enter to navigate."));
    elements.push_back(separator());

    if (show_loc) {
      elements.push_back(loc_menu->Render()|borderStyled(ftxui::Color(ftxui::Color::Orange1)));
      auto info = location_data[locations[sel_loc]];
      
      elements.push_back(window(text("Location Info"), vbox({
        text("Location: " + locations[sel_loc]),
        text("Items: " + info.items),
        text("Monsters: " + info.monsters),
        text("Villagers: " + info.villagers),
        text("coffin status : "+ info.coffin),
        text("heros :" + info.hero)
      })));
    }
    if (show_hero) {
      elements.push_back(window(text( " first hero info :"), vbox({
        text("hero  name :" + heros_data["hero name "]),
        text("action left : " +heros_data["action left "]),
        text("item have :" + heros_data["item have "]),
        text("perk have :" + heros_data["perk have "])
      })));
    }

    if (show_hero1)
    {
      elements.push_back(window(text( " secend hero info :"), vbox({
    text("hero  name :" + secend_heros_data["hero name "]),
        text("action left : " +secend_heros_data["action left "]),
        text("item have :" + secend_heros_data["item have "]),
        text("perk have :" + secend_heros_data["perk have "])
      })));
    }

    if (show_act) {
      elements.push_back(act_menu->Render() |borderStyled(ftxui::Color(ftxui::Color::Red1)));
      elements.push_back(window(text("Action Info"), vbox({
        text("Action: " + actions[sel_act]),
        paragraph(action_help[actions[sel_act]])
      })));
    }

if(show_task)
{
string re;
for (auto i1 : monster_list)
{
  re+=i1->get_mons_name()+" has "+to_string(i1->get_hidden_item()) +" task to do \n";
}
elements.push_back(window(text("task Detail"),paragraph(re)));
}

   if (show_map)
     { 
     
      elements.push_back(window(text("Map Detail"),
                               paragraph(map_ascii)));
     }
    
    return vbox(std::move(elements)) | border; });

  Component app = renderer | CatchEvent([&](Event event)
                                        {
    if (event == Event::Character('l') || event == Event::Character('L')) {
      show_loc = !show_loc;
     show_map= show_hero = show_hero1 = show_act = false;
      return true;
    }
    if (event == Event::Character('h') || event == Event::Character('H')) {
      show_hero = !show_hero;
     show_map= show_loc = show_hero1 = show_act = false;
      return true;
    }
    if (event == Event::Character('j') || event == Event::Character('J')) {
      show_hero1 = !show_hero1;
      show_map=show_loc = show_hero = show_act = false;
      return true;
    }
    if (event == Event::Character('a') || event == Event::Character('A')) {
      show_act = !show_act;
     show_map= show_loc = show_hero = show_hero1 = false;
      return true;
    }

      if (event==Event::Character('m') || event==Event::Character('M'))
      {
        show_map=!show_map;
        show_act=show_hero1=show_hero=show_loc=false;
        
        return true;
      }      
        if (event==Event::Character('t')|| event==Event::Character('T'))
        {
          show_task=!show_task;
               show_map= show_loc = show_hero = show_hero1 = false;
        }
        
     if (event == Event::Return) {
            string message;


       
        


if (show_map || show_hero ||show_hero1 ||show_task)
{
  return true;
}


      if (show_loc)
       message = locations[sel_loc];
     
      else if (show_act)
        message =actions[sel_act];
      else
        throw invalid_argument("enter not detected\n");
        ++enter_count;
        if (enter_count==1)
        {
          first_enter=message;
        }
        else if (enter_count==2)
        {
            secend_enter=message;
            screen.Exit();
        }
        
        
      return true;
     }
    if (show_loc)    return loc_menu->OnEvent(event);
    if (show_hero)    return hero_menu->OnEvent(event);
    if (show_act)    return act_menu->OnEvent(event);
    if(show_hero1)   return heros1_menu->OnEvent(event);
    // if (show_task)
    // {
    // return taks_menu->OnEvent(event);
    // }
    
    return false; });

  screen.Loop(app);
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
void programm::run()
{
  vector<string> locations = {"0 ) Hospital", "1 ) grave_yard", "2 ) church", "3 ) institute", "4 ) Lab", "5 ) shop", "6 ) museum", "7 ) cryptt", "8 ) abbey", "9 ) Mansion", "10 ) theatre", "11 ) tower", "12 ) docks", "13 ) inn", "14 ) precinct", "15 ) barn", "16 ) dungeon", "17 ) cave", "18 ) camp"};
  int gar_one, gar_two, place_go;
  string first_enter, secend_enter, player_one, player_two;
  LocationInfo data_updater;
  cout << "welcome to the HORRIFIED a city full of mistry" << endl;
  cout << "Master please enter your name" << endl;
  cin >> player_one;
  input_validation(player_one);
  cout << "Dear lord please enter your name" << endl;
  cin >> player_two;
  input_validation(player_two);
  cout << "get ready for the game  The player who last ate garlic the longest time ago will start the game" << endl;
  cout << player_one << " enter the last time you ate the garlic base on days " << endl;
  cin >> gar_one;
  cout << player_two << " enter the last time you ate the garlic base on days " << endl;
  cin >> gar_two;
  try
  {
    if (gar_one == 0 || gar_two == 0)
    {
      throw invalid_argument("not acceptable\n");
    }
  }
  catch (exception &e)
  {
    cerr << e.what();
    exit(0);
  }
  if (gar_one <= gar_two)
  {
    cout << "smart! lets start with the " << player_one << endl;
    cout << "enter the name of the hero  mayor or archaeologist " << endl;
    cin >> player_one;
    to_lowercase(player_one);
    input_validation(player_one);
    charecter_exist(player_one);
    if (player_one == "mayor")
    {
      cout << player_two << " start with " << "archaeologist" << endl;
      player_two = "archaeologist";
    }
    else
    {
      cout << player_two << " start with" << " mayor" << endl;
      player_two = "mayor";
    }
  }
  else
  {
    cout << "smart! lets start with the " << player_two << endl;
    cout << "enter the name of the hero mayor or archaeologist " << endl;
    cin >> player_two;
    to_lowercase(player_two);
    input_validation(player_two);
    charecter_exist(player_two);
    if (player_two == "mayor")
    {
      cout << player_one << " start with" << " archaeologist" << endl;
      player_one = "archaeologist";
    }
    else
    {
      cout << player_one << " start with" << " mayor" << endl;
      player_one = "mayor";
    }
  }
  cin.get();
  cout << "note : History is written by the victor. History is full of liars. If he survives and we perish, his truth will be recorded and ours will be lost." << endl;
  cin.get();
  cout << "enter two enter in the section" << endl;

  bool hero_phase = true;
  while (true)
  {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // cin.get();
    // clearScreen();
    // terminal_handler(data_updater, first_enter, secend_enter);

    for (auto hero : hero_list)
    {
      if (hero->get_hero_name() == player_one)
      {
        while (hero->get_action() > 0)
        {
          cin.get();
          clearScreen();
          terminal_handler(data_updater, first_enter, secend_enter);
          if (first_enter == "Move")
          {
            try
            {

              auto iterat = find(locations.begin(), locations.end(), secend_enter);
              place_go = iterat - locations.begin();
              while (!is_node_connected(hero->get_loc()->get_loc_relation(), place_go))
              {
                cout << "thats far away enter the place again" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin.get();
                clearScreen();
                terminal_handler(data_updater, first_enter, secend_enter);
                auto iterat = find(locations.begin(), locations.end(), secend_enter);
                place_go = iterat - locations.begin();
              }
              hero->move(list_of_location[place_go], *this);
              hero->set_action(hero->get_action() - 1);
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
            }
            catch (exception &e)
            {
              cout << e.what() << endl;
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);

              break;
            }
          }
          if (first_enter == "Guide")
          {
            try
            {
              hero->guide(my_map, *this);
              hero->set_action(hero->get_action() - 1);
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
            }
            catch (exception &e)
            {
              cout << e.what() << endl;
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);

              break;
            }
          }
          if (first_enter == "Pick Up")
          {
            try
            {
              hero->pickup();
              hero->set_action(hero->get_action() - 1);
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
            }
            catch (exception &e)
            {
              cout << e.what() << endl;
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
              break;
            }
          }
          if (first_enter == "Advance")
          {
            try
            {
              hero->advance(monster_list, *this);
              hero->set_action(hero->get_action() - 1);
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
            }
            catch (exception &e)
            {
              cout << e.what() << endl;
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
              break;
            }
          }
          if (first_enter == "Defeat")
          {
            try
            {
              hero->defeat(monster_list, *this);
              hero->set_action(hero->get_action() - 1);
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
            }
            catch (exception &e)
            {
              cout << e.what() << endl;
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);

              break;
            }
          }
          if (first_enter == "special action ")
          {
            try
            {
              hero->special_action(my_map, *this);
              hero->set_action(hero->get_action() - 1);
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
            }
            catch (exception &e)
            {
              cout << e.what() << endl;
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
              break;
            }
          }
          if (first_enter == "use perk")
          {
            try
            {
              hero->use_perk(*this);
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
            }
            catch (exception &e)
            {
              cout << e.what() << endl;
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
              break;
            }
          }

          if (first_enter == "Quit")
          {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            cout << "there is a message for you" << endl;
            clearScreen();
            cout << "Sacrifice is a choice you make. Loss is a choice made for you." << endl;
            return;
          }
        }
      }
    }
    for (auto mon : monster_list)
    {
      if (mon->get_did_attack())
      {
        mon->set_did_attack(false);
        continue;
      }
      else
      {
        try
        {
          int rand = 0;
          rand = random_number(0, static_cast<int>(monster_card_list.size()) - 1);
          monster_card_list[rand]->item_handler(*this);
          monster_card_list[rand]->event(my_map, list_of_location, *this);
          monster_card_list[rand]->monster_strike(*this, monster_list);
          delete monster_card_list[rand];
          monster_card_list.erase(monster_card_list.begin() + rand);

          if (monster_card_list.empty())
          {
            cout << "you lose the game " << endl;
            exit(0);
          }
          break;
        }
        catch (exception &e)
        {
          cerr << e.what() << endl;
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cin.get();
          clearScreen();
          terminal_handler(data_updater, first_enter, secend_enter);
          break;
        }
      }
    }

    cout << "monster_phase is over" << endl;
    for (auto mons1 : monster_list)
    {
      mons1->set_did_attack(false);
    }
    for (auto hero : hero_list)
    {
      if (typeid(*hero).name() == typeid(Mayor).name())
      {
        hero->set_action(5);
      }
      else
      {
        hero->set_action(4);
      }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // cin.get();
    // clearScreen();
    // terminal_handler(data_updater, first_enter, secend_enter);
    hero_phase = true;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // cin.get();
    // clearScreen();
    // terminal_handler(data_updater, first_enter, secend_enter);

    for (auto hero : hero_list)
    {
      if (hero->get_hero_name() == player_two)
      {
        while (hero->get_action() > 0)
        {
          cin.get();
          clearScreen();
          terminal_handler(data_updater, first_enter, secend_enter);
          if (first_enter == "Move")
          {
            try
            {

              auto iterat = find(locations.begin(), locations.end(), secend_enter);
              place_go = iterat - locations.begin();
              while (!is_node_connected(hero->get_loc()->get_loc_relation(), place_go))
              {
                cout << "thats far away enter the place again" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin.get();
                clearScreen();
                terminal_handler(data_updater, first_enter, secend_enter);
                auto iterat = find(locations.begin(), locations.end(), secend_enter);
                place_go = iterat - locations.begin();
              }
              hero->move(list_of_location[place_go], *this);
              hero->set_action(hero->get_action() - 1);
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
            }
            catch (exception &e)
            {
              cout << e.what() << endl;
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);

              break;
            }
          }
          if (first_enter == "Guide")
          {
            try
            {
              hero->guide(my_map, *this);
              hero->set_action(hero->get_action() - 1);
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
            }
            catch (exception &e)
            {
              cout << e.what() << endl;
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);

              break;
            }
          }
          if (first_enter == "Pick Up")
          {
            try
            {
              hero->pickup();
              hero->set_action(hero->get_action() - 1);
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
            }
            catch (exception &e)
            {
              cout << e.what() << endl;
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
              break;
            }
          }
          if (first_enter == "Advance")
          {
            try
            {
              hero->advance(monster_list, *this);
              hero->set_action(hero->get_action() - 1);
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
            }
            catch (exception &e)
            {
              cout << e.what() << endl;
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
              break;
            }
          }
          if (first_enter == "Defeat")
          {
            try
            {
              hero->defeat(monster_list, *this);
              hero->set_action(hero->get_action() - 1);
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
            }
            catch (exception &e)
            {
              cout << e.what() << endl;
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);

              break;
            }
          }
          if (first_enter == "special action ")
          {
            try
            {
              hero->special_action(my_map, *this);
              hero->set_action(hero->get_action() - 1);
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
            }
            catch (exception &e)
            {
              cout << e.what() << endl;
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
              break;
            }
          }
          if (first_enter == "use perk")
          {
            try
            {
              hero->use_perk(*this);
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
            }
            catch (exception &e)
            {
              cout << e.what() << endl;
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              // cin.get();
              // clearScreen();
              // terminal_handler(data_updater, first_enter, secend_enter);
              break;
            }
          }

          if (first_enter == "Quit")
          {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            cout << "there is a message for you" << endl;
            clearScreen();
            cout << "Sacrifice is a choice you make. Loss is a choice made for you." << endl;
            return;
          }
        }
      }
    }

    for (auto mon : monster_list)
    {
      if (mon->get_did_attack())
      {
        mon->set_did_attack(false);
        continue;
      }
      else
      {
        try
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
            exit(0);
          }
          break;
        }
        catch (exception &e)
        {
          cerr << e.what() << endl;
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          cin.get();
          clearScreen();
          terminal_handler(data_updater, first_enter, secend_enter);
          break;
        }
      }
    }
    for (auto mons1 : monster_list)
    {
      mons1->set_did_attack(false);
    }
    for (auto hero : hero_list)
    {
      if (typeid(*hero).name() == typeid(Mayor).name())
      {
        hero->set_action(5);
      }
      else
      {
        hero->set_action(4);
      }
    }
    cout << "monster_phase is over" << endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // cin.get();
    // clearScreen();
    // terminal_handler(data_updater, first_enter, secend_enter);
    hero_phase = true;
  }
}
