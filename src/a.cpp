#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
using namespace ftxui;
void clearScreen() {
    #ifdef __WIN32 
        system("cls");
    #else 
        system("clear");
    #endif
}
struct LocationInfo {
  string items;
  string monsters;
  string villagers;
};

void RenderGameUI() {
  auto screen = ScreenInteractive::TerminalOutput();

  const std::string map_ascii = R"MAP(
+---------------------------------------------------------------------------------------+
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
|                          bar<n  tower                                                 |
|                                │   \                                                  |
|                                │    docks                                             |
|                                └──── dungeon                                          |
+---------------------------------------------------------------------------------------+
)MAP";

  map<string, LocationInfo> location_data = {
    {"Lab",      {"Garlic(2)",   "None",        "Gholi (Barn)"}},
    {"Castle",   {"Stake(3)",    "Dracula",     "None"}},
    {"Barn",     {"Chemical(3)", "None",        "Golmamad (Lab)"}},
    {"Hospital", {"Bandage(1)",  "None",        "None"}},
    {"Mansion",  {"None",        "None",        "None"}},
    {"Bu-Ali",   {"None",        "Invisible",   "None"}}
  };

  map<string, string> action_help = {
    {"Move",    "Move to another location."},
    {"Guide",   "Guide a villager."},
    {"Pick Up", "Pick up an item."},
    {"Advance", "Advance game state."},
    {"Defeat",  "Fight a monster."},
    {"Use Perk","Use a special ability."},
    {"Help",    "Show help menu."},
    {"Quit",    "Exit the game."}
  };

  bool show_loc = false;
  bool show_hero = false;
  bool show_vil = false;
  bool show_act = false;

  int sel_loc = 0, sel_vil = 0, sel_act = 0;
  vector<string> locations = {"Lab","Castle","Barn","Bu-Ali","Hospital","Mansion"};
  vector<string> villagers = {"Ghoti","Golmamad"};
  vector<string> actions = {"Move","Guide","Pick Up","Advance","Defeat","Use Perk","Help","Quit"};

  auto loc_menu = Radiobox(&locations, &sel_loc);
  auto vil_menu = Radiobox(&villagers, &sel_vil);
  auto act_menu = Radiobox(&actions, &sel_act);

  string enter1, enter2;
  int enter_count = 0;

  Component renderer = Renderer([&] {
    Elements elements;
    elements.push_back(paragraph(map_ascii));
    elements.push_back(separator());
    elements.push_back(paragraph("Press L:Location, H:Hero, V:Villager, A:Action. Use arrows+Enter."));
    elements.push_back(separator());

    if (show_loc) {
      elements.push_back(loc_menu->Render() | border);
      auto info = location_data[locations[sel_loc]];
      elements.push_back(window(text("Location Info"), vbox({
        text("Location: " + locations[sel_loc]),
        text("Items: " + info.items),
        text("Monsters: " + info.monsters),
        text("Villagers: " + info.villagers)
      })));
    }
    if (show_hero) {
      elements.push_back(window(text("Hero Info"), paragraph("Hero details here.")));
    }
    if (show_vil) {
      elements.push_back(vil_menu->Render() | border);
      elements.push_back(window(text("Villager Info"), vbox({
        text("Name: " + villagers[sel_vil]),
        text("Location: TBD")
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
    return vbox(std::move(elements)) | border;
  });

  Component app = renderer | CatchEvent([&](Event event) {
    if (event == Event::Character('l') || event == Event::Character('L')) {
      show_loc = !show_loc; show_hero = show_vil = show_act = false; return true;
    }
    if (event == Event::Character('h') || event == Event::Character('H')) {
      show_hero = !show_hero; show_loc = show_vil = show_act = false; return true;
    }
    if (event == Event::Character('v') || event == Event::Character('V')) {
      show_vil = !show_vil; show_loc = show_hero = show_act = false; return true;
    }
    if (event == Event::Character('a') || event == Event::Character('A')) {
      show_act = !show_act; show_loc = show_hero = show_vil = false; return true;
    }
    if (event == Event::Return) {
      string message;
      if (show_loc)
        message = "ENTER in Location menu: " + locations[sel_loc];
      else if (show_hero)
        message = "ENTER in Hero panel";
      else if (show_vil)
        message = "ENTER in Villager menu: " + villagers[sel_vil];
      else if (show_act)
        message = "ENTER in Action menu: " + actions[sel_act];
      else
        message = "ENTER pressed";

      ++enter_count;
      if (enter_count == 1) {
        enter1 = message;
      } else if (enter_count == 2) {
        enter2 = message;
        screen.Exit();
      }
      return true;
    }
    if (show_loc)    return loc_menu->OnEvent(event);
    if (show_vil)    return vil_menu->OnEvent(event);
    if (show_act)    return act_menu->OnEvent(event);
    return false;
  });

  screen.Loop(app);

  cout << "First ENTER: " << enter1 << endl;
  cout << "Second ENTER: " << enter2 << endl;
}

int main() {
  RenderGameUI();
  clearScreen();
  RenderGameUI();
  return 0;
}
