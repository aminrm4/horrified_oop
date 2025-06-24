#include "programm.hpp"
using namespace std;
using namespace ftxui;
#include <bits/stdc++.h>
#include"Mayor.hpp"
#include"Archaeologist.hpp"
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <iostream>
int programm::night_terror = 0;
   void programm::clearScreen()
   {
    #ifdef __WIN32 
        system("cls");
    #else 
        system("clear");
    #endif
   }

set<int> programm::random_generator(int start, int end, int count)
{
  set<int> my_random;
  srand(time(nullptr));
  if (start - end + 1 < count)
  {
    throw logic_error("cant generate the random numbers \n");
  }

  while (count != my_random.size())
  {
    int random1 = start + rand() % (end - start + 1);
    my_random.insert(random1);
  }
  return my_random;
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

  for (size_t i = 0; i < 19; i++)
  {
    list_of_location[i] = new location(i, 0, nullptr, nullptr, nullptr, nullptr);
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
}
void programm::next_frenzy()
{

  if (monster_list.size() != 1)
  {

    if (monster_list[0]->get_is_frenzy() == false && monster_list[1] == false)
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
}
string programm::show_all_item(const vector<item *> &show, LocationInfo &state)
{
  state.items = "";
  map<string, int> same_element;
  for (const auto &i : show)
  {
    ++same_element[i->get_name()];
  }
  for (const auto &i : same_element)
  {
    state.items = state.items + " " + (i.first + "(" + to_string(i.second) + ")");
  }
  return state.items;
}

perk *programm::set_award(int index)
{
  return list_of_perks[index];
}
string programm::show_all_villager(const vector<villager *> &show, LocationInfo &state)
{
  state.villagers = "";
  map<string, int> same_element;
  for (const auto &i : show)
  {
    ++same_element[i->get_name()];
  }
  for (const auto &i : same_element)
  {
    state.villagers = state.villagers + " " + (i.first + "(" + to_string(i.second) + ")");
  }
  return state.villagers;
}

string programm::show_all_hero(const vector<hero *> &show, LocationInfo &state)
{
  state.hero = "";
  map<string, int> same_element;
  for (const auto &i : show)
  {
    ++same_element[i->get_hero_name()];
  }
  for (const auto &i : same_element)
  {
    state.hero = state.hero + " " + (i.first + "(" + to_string(i.second) + ")");
  }
  return state.hero;
}
string programm::show_all_mosnter(const vector<monster *> &show, LocationInfo &state)
{
  state.monsters = "";
  map<string, int> same_element;
  for (const auto &i : show)
  {
    ++same_element[i->get_mons_name()];
  }
  for (const auto &i : same_element)
  {
    state.monsters = state.monsters + " " + (i.first + "(" + to_string(i.second) + ")");
  }
  return state.monsters;
} 
template <typename T>
  string  programm::show_hero_deatail(T)
  {
    string temp="";
    map<string,int>same_element;
    for ( const auto &i : T)
    {
      ++same_element[i.get_name()];
    }

      for (const auto &i : same_element)
      {
          temp=temp+ " "+ i.first+"("+to_string(i.second)+")";
      }
      return temp;
  }

void programm::terminal_handler(LocationInfo &info,string & first_enter,string &secend_enter)
{
int enter_count=0;
  auto screen = ScreenInteractive::TerminalOutput();

  static const std::string map_ascii = R"MAP(
+---------------------------------------------------------------------------------------+
|                                                                                       |
|                       )MAP";get_night_terror() ;R"MAP(                                |
|                                                                                       |
|                                    institute                                          |
|                                       │                                               |
|                                   laboratory                                          |
|                             |---------                                                |
|        hospital             |   grave_yard                museum                      |
|           \                 |     │    |----------------------                        |                          
|            \         |----- | ---------  |                                            |
|              \       |      |     │      |                                            |
|                   church────shop────mansion────abbey────cryptt                        |
|                              │    \    \       \                                      |
|                              │  ---------------------|                                |
|                           theatre--precinct  inn    camp────cave                      |
|                            /  |  \                                                    |
|                          barn  tower                                                  |
|                                │   \                                                  |
|                                │    docks                                             |
|                                └──── dungeon                                          |
+---------------------------------------------------------------------------------------+
)MAP";
 
  map<string, LocationInfo> location_data = {
      {"Lab", {
                  show_all_item(list_of_location[4]->get_item_list(), info),
                  show_all_hero(list_of_location[4]->get_hero_list(), info),
                  show_all_mosnter(list_of_location[4]->get_monster_list(), info),
                  show_all_villager(list_of_location[4]->get_villager_list(), info),
              }},

      {"church", {
        show_all_item(list_of_location[2]->get_item_list(), info),
         show_all_hero(list_of_location[2]->get_hero_list(),info),
          show_all_mosnter(list_of_location[2]->get_monster_list(),info),
           show_all_villager(list_of_location[2]->get_villager_list(),info),
          }},
      {"grave_yard",
         {show_all_item(list_of_location[1]->get_item_list(), info),
           show_all_hero(list_of_location[1]->get_hero_list(),info),
            show_all_mosnter(list_of_location[1]->get_monster_list(),info), 
            show_all_villager(list_of_location[1]->get_villager_list(),info),
          }},
      {"Hospital",
         {show_all_item(list_of_location[0]->get_item_list(), info),
           show_all_hero(list_of_location[0]->get_hero_list(),info), 
           show_all_mosnter(list_of_location[0]->get_monster_list(),info),
            show_all_villager(list_of_location[0]->get_villager_list(),info),
          }},
      {"Mansion",
         {show_all_item(list_of_location[9]->get_item_list(), info),
           show_all_hero(list_of_location[9]->get_hero_list(),info), 
           show_all_mosnter(list_of_location[9]->get_monster_list(),info),
            show_all_villager(list_of_location[9]->get_villager_list(),info),
          }},
      {"institute",
         {show_all_item(list_of_location[3]->get_item_list(), info),
           show_all_hero(list_of_location[3]->get_hero_list(),info),
            show_all_mosnter(list_of_location[3]->get_monster_list(),info),
             show_all_villager(list_of_location[3]->get_villager_list(),info),
            }},
      {"museum",
         {show_all_item(list_of_location[6]->get_item_list(), info),
           show_all_hero(list_of_location[6]->get_hero_list(),info), 
           show_all_mosnter(list_of_location[6]->get_monster_list(),info),
            show_all_villager(list_of_location[6]->get_villager_list(),info),
          }},
      {"shop",
         {show_all_item(list_of_location[5]->get_item_list(), info), 
          show_all_hero(list_of_location[5]->get_hero_list(),info),
           show_all_mosnter(list_of_location[5]->get_monster_list(),info),
            show_all_villager(list_of_location[5]->get_villager_list(),info),
          }},
      {"cave",
         {show_all_item(list_of_location[17]->get_item_list(), info),
           show_all_hero(list_of_location[17]->get_hero_list(),info),
            show_all_mosnter(list_of_location[17]->get_monster_list(),info),
             show_all_villager(list_of_location[17]->get_villager_list(),info),
            }},
      {"camp",
         {show_all_item(list_of_location[18]->get_item_list(), info),
           show_all_hero(list_of_location[18]->get_hero_list(),info), 
           show_all_mosnter(list_of_location[18]->get_monster_list(),info),
            show_all_villager(list_of_location[18]->get_villager_list(),info),
          }},
      {"barn",
         {show_all_item(list_of_location[15]->get_item_list(), info), 
          show_all_hero(list_of_location[15]->get_hero_list(),info),
           show_all_mosnter(list_of_location[15]->get_monster_list(),info), 
           show_all_villager(list_of_location[15]->get_villager_list(),info),
          }},
      {"dungeon", 
        {show_all_item(list_of_location[16]->get_item_list(), info), 
          show_all_hero(list_of_location[16]->get_hero_list(),info),
           show_all_mosnter(list_of_location[16]->get_monster_list(),info), 
           show_all_villager(list_of_location[16]->get_villager_list(),info),
          }},
      {"tower",
         {show_all_item(list_of_location[11]->get_item_list(), info),
           show_all_hero(list_of_location[11]->get_hero_list(),info),
            show_all_mosnter(list_of_location[11]->get_monster_list(),info),
             show_all_villager(list_of_location[11]->get_villager_list(),info),
            }},
      {"inn",
         {show_all_item(list_of_location[13]->get_item_list(), info),
           show_all_hero(list_of_location[13]->get_hero_list(),info), 
           show_all_mosnter(list_of_location[13]->get_monster_list(),info),
            show_all_villager(list_of_location[13]->get_villager_list(),info),
          }},
      {"docks",
         {show_all_item(list_of_location[12]->get_item_list(), info),
           show_all_hero(list_of_location[12]->get_hero_list(),info),
            show_all_mosnter(list_of_location[12]->get_monster_list(),info),
             show_all_villager(list_of_location[12]->get_villager_list(),info),
            }},
      {"theatre", 
        {show_all_item(list_of_location[10]->get_item_list(), info),
           show_all_hero(list_of_location[10]->get_hero_list(),info),
            show_all_mosnter(list_of_location[10]->get_monster_list(),info),
             show_all_villager(list_of_location[10]->get_villager_list(),info),
            }},
      {"abbey",
         {show_all_item(list_of_location[8]->get_item_list(), info),
           show_all_hero(list_of_location[8]->get_hero_list(),info),
            show_all_mosnter(list_of_location[8]->get_monster_list(),info), 
            show_all_villager(list_of_location[8]->get_villager_list(),info),
          }},
      {"cryptt", 
        {show_all_item(list_of_location[7]->get_item_list(), info),
           show_all_hero(list_of_location[7]->get_hero_list(),info),
            show_all_mosnter(list_of_location[7]->get_monster_list(),info), 
            show_all_villager(list_of_location[7]->get_villager_list(),info),
          }},
      {"precinct", 
        {show_all_item(list_of_location[14]->get_item_list(), info),
           show_all_hero(list_of_location[14]->get_hero_list(),info),
            show_all_mosnter(list_of_location[14]->get_monster_list(),info), 
            show_all_villager(list_of_location[14]->get_villager_list(),info),
          }}};
  map<string, string> action_help = {
      {"Move", "Move to another location."},
      {"Guide", "move the villager one step to the hero,or move a villager to the neighbor house base on the hero location"},
      {"Pick Up", "can pick up desired items"},
      {"Advance", "can improve the task for defeating a monster."},
      {"Defeat", "kill a monster when all taks has been done(should be in the same place with mosnter)"},
      {"special action", "use it for archzeologist to pick up the items in the  neighbor locations"},
      {"Quit", "Exit the game.(your data will be lost)"},
      {"use perk","use the perk wich hero have(from hero panel)"}
    };
map<string,string > heros_data={
{ "hero name ",hero_list[0] ->get_hero_name()},
{"item have " ,show_hero_deatail(hero_list[0]->get_items())},
{"perk have ",show_hero_deatail(hero_list[0]->get_perks())},
{"action left ",to_string( hero_list[0]->get_action())}
                           
};

map<string,string>secend_heros_data={

{ "hero name ",hero_list[1] ->get_hero_name()},
{"item have " ,show_hero_deatail(hero_list[1]->get_items())},
{"perk have ",show_hero_deatail(hero_list[1]->get_perks())},
{"action left ",to_string( hero_list[1]->get_action())}
};
  bool show_loc = false;
  bool show_hero = false;
  bool show_act = false;
  bool show_hero1=false;
  int sel_loc = 0, sel_act = 0;
  int sel_hero=0;
  int sel_hero1=0;
  
  vector<string> locations = {"Lab", "church", "grave_yard", "Hospital", "Mansion", "institute","museum","shop","cave","camp","barn","dungeon","tower","inn","docks","theatre","abbey","cryptt","precinct"};
  vector<string> actions = {"Move", "Guide", "Pick Up", "Advance", "Defeat", "special action ",  "Quit","use perk"};
    vector<string>heros={"hero name ","item have ","perk have ","action left "};
    vector<string>heros1={"hero name ","item have ","perk have ","action left "};
  auto loc_menu = Radiobox(&locations, &sel_loc);
  auto act_menu = Radiobox(&actions, &sel_act);
  auto hero_menu=Radiobox(&heros,&sel_hero);
  auto heros1_menu=Radiobox(&heros1,&sel_hero1);
  Component renderer = Renderer([&]
                                {
    Elements elements;
    elements.push_back(paragraph(map_ascii));
    elements.push_back(separator());
    elements.push_back(paragraph("Press L:Location, H:Hero,  J: secend Hero ,  A:Action. Use arrows+Enter to navigate."));
    elements.push_back(separator());

    if (show_loc) {
      elements.push_back(loc_menu->Render() | border);
      auto info = location_data[locations[sel_loc]];
      
      elements.push_back(window(text("Location Info"), vbox({
        text("Location: " + locations[sel_loc]),
        text("Items: " + info.items),
        text("Monsters: " + info.monsters),
        text("Villagers: " + info.villagers),
        text("heros :" + info.hero)
      })));
    }
    if (show_hero) {
      elements.push_back(hero_menu->Render() | border);

      elements.push_back(window(text( " first hero info :"), vbox({
        text("hero  name :" + heros_data[heros[sel_hero]]),
        text("action left : " + heros_data[heros[sel_hero]]),
        text("item have :" + heros_data[heros[sel_hero]]),
        text("perk have :" + heros_data[heros[sel_hero]])
      })));
    }

    if (show_hero1)
    {
      elements.push_back(heros1_menu->Render() | border);

      elements.push_back(window(text( " secend hero info :"), vbox({
        text("hero  name :" + secend_heros_data[heros1[sel_hero1]]),
        text("action left : " +  secend_heros_data[heros1[sel_hero1]]),
        text("item have :" +  secend_heros_data[heros1[sel_hero1]]),
        text("perk have :" + secend_heros_data [heros1[sel_hero1]])
      })));
    }
    
    if (show_act) {
      elements.push_back(act_menu->Render() | border);
      elements.push_back(window(text("Action Info"), vbox({
        text("Action: " + actions[sel_act]),
        paragraph(action_help[actions[sel_act]])
      })));
    }

    
elements.push_back(separator());
    return vbox(std::move(elements)) | border; });

Component app = renderer | CatchEvent([&](Event event) {
    if (event == Event::Character('l') || event == Event::Character('L')) {
      show_loc = !show_loc;
      show_hero = show_hero1 = show_act = false;
      return true;
    }
    if (event == Event::Character('h') || event == Event::Character('H')) {
      show_hero = !show_hero;
      show_loc = show_hero1 = show_act = false;
      return true;
    }
    if (event == Event::Character('j') || event == Event::Character('J')) {
      show_hero1 = !show_hero1;
      show_loc = show_hero = show_act = false;
      return true;
    }
    if (event == Event::Character('a') || event == Event::Character('A')) {
      show_act = !show_act;
      show_loc = show_hero = show_hero1 = false;
      return true;
    }



     if (event == Event::Return) {
            string message;


       
        


      if (show_loc)
       message = locations[sel_loc];
      else if (show_hero)
        message = heros_data[heros[sel_hero]];
      else if (show_hero1)
        message =  secend_heros_data[heros1[sel_hero1]];
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
    return false;
  });

  screen.Loop(app);
}

void programm::run()
{
  cout << "welcome to HORRIFIED place full of mystery";
}
