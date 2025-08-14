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
#include "free_func.hpp"
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

namespace fs = std::filesystem;

void programm::save_game(string file_name,vector<int>&st)
{
  fs::path dir = file_name;
  if (!fs::is_empty(dir))
  {
    for (auto const &entry : fs::directory_iterator(dir))
    {
      fs::remove_all(entry.path());
    }
  }

  fs::path full_path = dir / "items.txt";
  for (auto it : list_of_items)
  {
    it->save_game(full_path.string());
  }
  full_path = dir / "perks.txt";

  for (auto pe : list_of_perks)
  {
    pe->save_game(full_path.string());
  }
  full_path = dir / "monster.txt";
  for (auto mo : monster_list)
  {
    if (typeid(*mo).name() == typeid(Drakula).name())
    {
      full_path = dir / "Drakula.txt";
      mo->save_game(full_path.string());
    }
    else
    {
      full_path = dir / "Invisible_man.txt";
      mo->save_game(full_path.string());
    }
  }
  for (auto he : hero_list)
  {
    full_path=dir/"hero.txt";
    he->save_game(full_path.string());
    
  }
  full_path = dir / "monster_card.txt";
  for (auto ca : monster_card_list)
  {
    ca->save_game(full_path.string());
  }
  full_path = dir / "villager.txt";

  for (auto lo : list_of_location)
  {
    for (auto vi : lo->get_villager_list())
    {
      vi->save_game(full_path.string());
    }
  }
  full_path = dir / "location.txt";
  for (auto loc : list_of_location)
  {
    loc->save_game(full_path.string());
  }
  
  full_path = dir / "game_state.txt";
  save_game_state(st,full_path.string());

}

void programm::load_game(string file_name)
{
  load_game_hero(file_name, *this);

  for (auto ca : monster_card_list)
  {
    ca->load_game(file_name, *this);
  }

  for (auto mo : monster_list)
  {
    mo->load_game(file_name, *this);
  }

  for (auto lo : list_of_location)
  {
    lo->load_game(file_name, *this);
    break;
  }

  for (auto ite : list_of_items)
  {
    ite->load_game(file_name, *this);
    break;
  }

  for (auto pe : list_of_perks)
  {
    pe->load_game(file_name, *this);
    break;
  }
  load_game_state(file_name,*this);
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

  list_of_items.push_back(new item(2, "Flower", rgb::Color::Yellow, list_of_location[12]));
  list_of_items.push_back(new item(2, "Flower", rgb::Color::Yellow, list_of_location[12]));

  list_of_items.push_back(new item(3, "Tarot", rgb::Color::Yellow, list_of_location[18]));
  list_of_items.push_back(new item(3, "Tarot", rgb::Color::Yellow, list_of_location[18]));

  list_of_items.push_back(new item(2, "Garlic", rgb::Color::Yellow, list_of_location[13]));
  list_of_items.push_back(new item(2, "Garlic", rgb::Color::Yellow, list_of_location[13]));

  list_of_items.push_back(new item(3, "Mirrored_Box", rgb::Color::Yellow, list_of_location[9]));
  list_of_items.push_back(new item(3, "Mirrored_Box", rgb::Color::Yellow, list_of_location[9]));

  list_of_items.push_back(new item(3, "Stake", rgb::Color::Yellow, list_of_location[8]));
  list_of_items.push_back(new item(3, "Stake", rgb::Color::Yellow, list_of_location[8]));

  list_of_items.push_back(new item(4, "Scroll", rgb::Color::Yellow, list_of_location[6]));
  list_of_items.push_back(new item(4, "Scroll", rgb::Color::Yellow, list_of_location[6]));

  list_of_items.push_back(new item(3, "Violin", rgb::Color::Yellow, list_of_location[18]));
  list_of_items.push_back(new item(3, "Violin", rgb::Color::Yellow, list_of_location[18]));

  list_of_items.push_back(new item(3, "Tablet", rgb::Color::Yellow, list_of_location[6]));
  list_of_items.push_back(new item(3, "Tablet", rgb::Color::Yellow, list_of_location[6]));

  list_of_items.push_back(new item(4, "Wolfsbane", rgb::Color::Yellow, list_of_location[18]));
  list_of_items.push_back(new item(4, "Wolfsbane", rgb::Color::Yellow, list_of_location[18]));

  list_of_items.push_back(new item(4, "Charm", rgb::Color::Yellow, list_of_location[18]));
  list_of_items.push_back(new item(4, "Charm", rgb::Color::Yellow, list_of_location[18]));

  // red items
  list_of_items.push_back(new item(2, "Dart", rgb::Color::Red, list_of_location[13]));
  list_of_items.push_back(new item(2, "Dart", rgb::Color::Red, list_of_location[13]));

  list_of_items.push_back(new item(3, "FirePoker", rgb::Color::Red, list_of_location[9]));
  list_of_items.push_back(new item(3, "FirePoker", rgb::Color::Red, list_of_location[9]));

  list_of_items.push_back(new item(5, "Rapier", rgb::Color::Red, list_of_location[10]));
  list_of_items.push_back(new item(5, "Rapier", rgb::Color::Red, list_of_location[10]));

  list_of_items.push_back(new item(2, "Shovel", rgb::Color::Red, list_of_location[1]));
  list_of_items.push_back(new item(2, "Shovel", rgb::Color::Red, list_of_location[1]));

  list_of_items.push_back(new item(5, "Torch", rgb::Color::Red, list_of_location[15]));
  list_of_items.push_back(new item(5, "Torch", rgb::Color::Red, list_of_location[15]));

  list_of_items.push_back(new item(4, "Pitchfork", rgb::Color::Red, list_of_location[15]));
  list_of_items.push_back(new item(4, "Pitchfork", rgb::Color::Red, list_of_location[15]));

  list_of_items.push_back(new item(6, "Rifle", rgb::Color::Red, list_of_location[15]));
  list_of_items.push_back(new item(6, "Rifle", rgb::Color::Red, list_of_location[15]));

  list_of_items.push_back(new item(6, "SilverCane", rgb::Color::Red, list_of_location[5]));
  list_of_items.push_back(new item(6, "SilverCane", rgb::Color::Red, list_of_location[5]));

  list_of_items.push_back(new item(3, "Knife", rgb::Color::Red, list_of_location[12]));
  list_of_items.push_back(new item(3, "Knife", rgb::Color::Red, list_of_location[12]));

  list_of_items.push_back(new item(6, "Pistol", rgb::Color::Red, list_of_location[14]));
  list_of_items.push_back(new item(6, "Pistol", rgb::Color::Red, list_of_location[14]));

  list_of_items.push_back(new item(4, "BearTrap", rgb::Color::Red, list_of_location[5]));
  list_of_items.push_back(new item(4, "BearTrap", rgb::Color::Red, list_of_location[5]));

  list_of_items.push_back(new item(4, "Speargun", rgb::Color::Red, list_of_location[3]));
  list_of_items.push_back(new item(4, "Speargun", rgb::Color::Red, list_of_location[3]));

  // blue items
  list_of_items.push_back(new item(1, "AnatomyText", rgb::Color::Blue, list_of_location[3]));
  list_of_items.push_back(new item(1, "AnatomyText", rgb::Color::Blue, list_of_location[3]));

  list_of_items.push_back(new item(1, "Centrifuge", rgb::Color::Blue, list_of_location[4]));
  list_of_items.push_back(new item(1, "Centrifuge", rgb::Color::Blue, list_of_location[4]));

  list_of_items.push_back(new item(1, "Kite", rgb::Color::Blue, list_of_location[11]));
  list_of_items.push_back(new item(1, "Kite", rgb::Color::Blue, list_of_location[11]));

  list_of_items.push_back(new item(2, "Research", rgb::Color::Blue, list_of_location[11]));
  list_of_items.push_back(new item(2, "Research", rgb::Color::Blue, list_of_location[11]));

  list_of_items.push_back(new item(2, "Telescope", rgb::Color::Blue, list_of_location[9]));
  list_of_items.push_back(new item(2, "Telescope", rgb::Color::Blue, list_of_location[9]));

  list_of_items.push_back(new item(2, "Searchlight", rgb::Color::Blue, list_of_location[14]));
  list_of_items.push_back(new item(2, "Searchlight", rgb::Color::Blue, list_of_location[14]));

  list_of_items.push_back(new item(2, "Experiments", rgb::Color::Blue, list_of_location[4]));
  list_of_items.push_back(new item(2, "Experiments", rgb::Color::Blue, list_of_location[4]));

  list_of_items.push_back(new item(2, "Analysis", rgb::Color::Blue, list_of_location[3]));
  list_of_items.push_back(new item(2, "Analysis", rgb::Color::Blue, list_of_location[3]));

  list_of_items.push_back(new item(3, "Rotenone", rgb::Color::Blue, list_of_location[3]));
  list_of_items.push_back(new item(3, "Rotenone", rgb::Color::Blue, list_of_location[3]));

  list_of_items.push_back(new item(3, "CosmicRayDiffuser", rgb::Color::Blue, list_of_location[11]));
  list_of_items.push_back(new item(3, "CosmicRayDiffuser", rgb::Color::Blue, list_of_location[11]));

  list_of_items.push_back(new item(3, "Nebularium", rgb::Color::Blue, list_of_location[11]));
  list_of_items.push_back(new item(3, "Nebularium", rgb::Color::Blue, list_of_location[11]));

  list_of_items.push_back(new item(3, "MonocaneMixture", rgb::Color::Blue, list_of_location[13]));
  list_of_items.push_back(new item(3, "MonocaneMixture", rgb::Color::Blue, list_of_location[13]));

  list_of_items.push_back(new item(3, "Fossil", rgb::Color::Blue, list_of_location[18]));
  list_of_items.push_back(new item(3, "Fossil", rgb::Color::Blue, list_of_location[18]));

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

perk *programm::set_award(int index)
{
  return list_of_perks[index];
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
bool isNumeric(const std::string &str)
{
  return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}
void renderItem(location *loc, sf::RenderWindow &window)
{
  string defaultt = "../Horrified_Assets/Items";
  string Ritem = defaultt + "/Red", Bitem = defaultt + "/Blue", Yitem = defaultt + "/Yellow";
  for (int i = 0; i < loc->get_item_list().size(); i++)
  {
    sf::Texture texture;
    sf::Sprite image;
    switch (loc->get_item_list()[i]->get_Color())
    {
    case rgb::Color::Red:
    {
      if (!texture.loadFromFile(Ritem + '/' + loc->get_item_list()[i]->get_name() + ".png"))

      {
        throw out_of_range("coudnt load a red item");
      }
    }
    break;
    case rgb::Color::Blue:
    {
      if (!texture.loadFromFile(Bitem + '/' + loc->get_item_list()[i]->get_name() + ".png"))

      {
        throw out_of_range("coudnt load a Blue item");
      }
    }
    break;
    case rgb::Color::Yellow:
    {
      if (!texture.loadFromFile(Yitem + '/' + loc->get_item_list()[i]->get_name() + ".png"))

      {
        throw out_of_range("coudnt load a yellow item");
      }
    }
    break;
    default:
      break;
    }
    image.setTexture(texture);
    image.setScale({200.f / texture.getSize().x, 200.f / texture.getSize().y});
    image.setPosition({250.f * (i % 7), 200.f * (i / 7)});
    window.draw(image);
  }
}

bool isclied(const sf::RectangleShape &rect, const sf::Event &event, const sf::RenderWindow &window)
{
  if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
  {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (rect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
    {
      return true;
    }
  }
  return false;
}
void MonsterPhase(programm &programm, sf::RenderWindow &window)
{
  int rand = 0;
  rand = random_number(0, static_cast<int>(programm.monster_card_list.size()) - 1);
  programm.monster_card_list[rand]->item_handler(programm);
  programm.monster_card_list[rand]->event(programm.my_map, programm.list_of_location, programm);

  Button next({100, 50}, {1500, 800}, "Next");
  std::string name = programm.monster_card_list[rand]->getName();

  if (programm.monster_card_list.empty())
  {
    exit(0);
  }
  massage massage({600.f, 450.f}, "the " + name + " Card played", sf::Color::Red, 64);

  sf::Texture texture, bg;
  if (!texture.loadFromFile("../Horrified_Assets/Monster_Cards/" + name + ".png"))
    throw out_of_range("cant open " + name + "monster card");
  sf::Sprite monsterCard(texture);

  if (!bg.loadFromFile("../Horrified_Assets/MonserPhaseBG.png"))
    throw out_of_range("cant load MonserPhaseBG.png");
  sf::Texture t3;
  t3.create(window.getSize().x, window.getSize().y);
  t3.update(window);

  sf::Image screenshot = t3.copyToImage(); //
  sf::Sprite Bg(t3);
  sf::RectangleShape fade({1920, 1080});
  fade.setFillColor(sf::Color(0, 0, 0, 175));
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (next.isClicked(event, window))
      {
        window.setActive(false);
        programm.monster_card_list[rand]->monster_strike(programm, programm.monster_list);
        window.setActive();

        delete programm.monster_card_list[rand];
        programm.monster_card_list.erase(programm.monster_card_list.begin() + rand);
        return;
      }

      // if (event.type == sf::Event::Closed) // fix here
      //   window.close();
    }
    window.clear(sf::Color(0, 0, 0, 175));
    window.draw(Bg);
    window.draw(fade);
    next.draw(window);
    massage.draw(window);
    window.display();
  }
}
void showInvisiblemanMat(sf::RenderWindow &window, vector<int> &map_check)
{
  sf::Texture texture;
  if (!texture.loadFromFile("../Horrified_Assets/Monster_Mat/InvisibleManMat.png"))
  {
    throw out_of_range("coulnt open InvisibleManMat.png");
  }
  sf::Sprite bg(texture, sf::IntRect(0, 950, texture.getSize().x, texture.getSize().y - 950));
  bg.setScale({1920.f / texture.getSize().x, 1050.f / (texture.getSize().y - 950)});

  Button back({100, 50}, {1920 - 400, 1080 - 200}, "Back");
  massage inn({500, 400}, "X", sf::Color::Red, 100);
  massage barn({1320, 365}, "X", sf::Color::Red, 100);
  massage mansion({345, 725}, "X", sf::Color::Red, 100);
  massage lab({910, 750}, "X", sf::Color::Red, 100);
  massage institude({1475, 700}, "X", sf::Color::Red, 100);
  map<int, massage> infos;
  infos[3] = institude;
  infos[4] = lab;
  infos[9] = mansion;
  infos[13] = inn;
  infos[15] = barn;

  for (int val : map_check)
  {
    infos.erase(val);
  }
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (back.isClicked(event, window))
        return;
    }
    window.clear();
    window.draw(bg);
    back.draw(window);
    for (auto &[key, msg] : infos)
    {
      msg.draw(window);
    }

    window.display();
  }
}
void programm::run(bool loadingSave)
{
  

 

  vector<pair<string, int>> usersinfo(2);
  enum initstate
  {
    showmonstercard,
    showitemlocation,
    infopage,
    heroSelection1,
    heroSelection2,
    exit,
    playmenu
  };
  sf::Texture Frenzy;

  if (!Frenzy.loadFromFile("../Horrified_Assets/FerenzyAsset.png"))
    throw out_of_range("couldnt load FerenzyAsset.png");

  sf::Sprite FrenzyMonster(Frenzy);
  FrenzyMonster.setScale({100.f / Frenzy.getSize().x, 100.f / Frenzy.getSize().y});
  FrenzyMonster.setPosition(1655, 575);

  initstate state = initstate::infopage;
  if (loadingSave)
  {
    state = initstate::playmenu;
  }
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
  Button next({100, 50}, {1920 - 175, 1080 - 150}, "Next");
  Button back({100, 50}, {1920 - 400, 1080 - 200}, "Back");

  massage massage1({(1920.f / 2) - (850.f / 2), 100.f}, "Player one please enter your information", sf::Color::Red, 52);
  massage massage2({(1920.f / 2) - (850.f / 2), 600.f}, "Player two please enter your information", sf::Color::Red, 52);

  TextInputBox playerName1({(1920.f / 2) - (500.f / 2), 200.f}, {500.f, 50.f});
  TextInputBox playerGarlic1({(1920.f / 2) - (500.f / 2), 300.f}, {500.f, 50.f});

  TextInputBox playerName2({(1920.f / 2) - (500.f / 2), 700.f}, {500.f, 50.f});
  TextInputBox playerGarlic2({(1920.f / 2) - (500.f / 2), 800.f}, {500.f, 50.f});

  Button2 monsterCard({375.f, 250.f}, {1500, 100}, "../Horrified_Assets/MonstercardBack.png");

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
  Button move(button, {115.f, 350.f}, "Move");
  Button ability(button, {move.getPosButton().x, move.getPosButton().y + 75}, "special action");
  Button defeat(button, {move.getPosButton().x, ability.getPosButton().y + 75}, "Defeat");
  Button advance(button, {move.getPosButton().x, defeat.getPosButton().y + 75}, "advance");
  Button pickup(button, {move.getPosButton().x, advance.getPosButton().y + 75}, "pick up");
  Button guide(button, {move.getPosButton().x, pickup.getPosButton().y + 75}, "Guide");
  Button items(button, {move.getPosButton().x, guide.getPosButton().y + 75}, "deatail");
  Button perks(button, {move.getPosButton().x, items.getPosButton().y + 75}, " use perk");
  std::vector<sf::Vector2f> locationPositions = {
      {800, 900},  // 0: Hospital
      {1015, 855}, // 1: Graveyard
      {870, 750},  // 2: Church
      {1250, 875}, // 3: Institute
      {1100, 725}, // 4: Laboratory
      {960, 580},  // 5: Shop
      {610, 735},  // 6: Museum
      {450, 750},  // 7: Crypt
      {500, 540},  // 8: Abbey
      {670, 490},  // 9: Mansion
      {1055, 305}, // 10: Theatre
      {1300, 300}, // 11: Tower///////
      {1340, 477}, // 12: Docks///////////
      {985, 100},  // 13: Inn
      {790, 150},  // 14: Precinct
      {1150, 120}, // 15: Barn
      {1375, 125}, // 16: Dungeon
      {455, 208},  // 17: Cave
      {600, 170}   // 18: Camp
  };

  vector<sf::RectangleShape> location_Button(19);
  for (int i = 0; i < 19; i++)
  {
    location_Button[i].setPosition(locationPositions[i]);
    location_Button[i].setSize({100.f, 100.f});
    location_Button[i].setFillColor(sf::Color::Transparent);
  }

  if (!map_texture.loadFromFile("../Horrified_Assets/map.png"))
  {
    throw out_of_range("coudnt find the map asset \n");
  }
  vector<Button2> B;
  Button2 Mayor(Button2({225, 300}, {500.f, 300.f}, "../Horrified_Assets/Heros/Mayor.png"));
  Button2 Archaeologist(Button2({225, 300}, {725, 300}, "../Horrified_Assets/Heros/Archaeologist.png"));
  Button2 courier(Button2({225, 300}, {950, 300}, "../Horrified_Assets/Heros/Courier.png"));
  Button2 scientist(Button2({225, 300}, {1175, 300}, "../Horrified_Assets/Heros/Scientist.png"));
  Button2 invisiblemanMat({270, 180}, {1550.f, 400.f}, "../Horrified_Assets/Monster_Mat/Precinct.png");
  vector<int> Nohero;
  int heroNo = 0;
  int locationshow = 0;
  int selectionNo = 0;

  if (loadingSave == true)
  {
    state = initstate::playmenu;
  }

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (state == initstate::showitemlocation)
      {
        if (back.isClicked(event, window))
          state = initstate::playmenu;
      }
      if (state == initstate::showmonstercard)
      {
        if (back.isClicked(event, window))
          state = initstate::playmenu;
      }
      if (state == initstate::playmenu) // hero phase
      {
        if (monsterCard.isClicked(event, window))
        {
          state = initstate::showmonstercard;
        }
        if (hero_list[heroNo]->get_action() <= 0)
        {

          MonsterPhase(*this, window);
          if (typeid(*hero_list[heroNo]).name() == typeid(class Mayor).name())
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
        for (int i = 0; i < location_Button.size(); i++)
        {
          if (isclied(location_Button[i], event, window))
          {
            state = initstate::showitemlocation;
            locationshow = i;
          }
        }
        if (invisiblemanMat.isClicked(event, window))
        {
          showInvisiblemanMat(window, vec);
        }
        if (move.isClicked(event, window))
        {

          int location = showLocationTextBox(window, *this, *hero_list[heroNo]);
          if (location >= 0)
          {
            hero_list[heroNo]->move(list_of_location[location], *this);
            hero_list[heroNo]->set_action(hero_list[heroNo]->get_action() - 1);
          }
          else
          {
            showCenteredTextBox(window, "ohh you exit the move action");
          }
        }
        if (ability.isClicked(event, window))
        {
          hero_list[heroNo]->special_action(my_map, *this, window);
          hero_list[heroNo]->set_action(hero_list[heroNo]->get_action() - 1);
        }
        if (defeat.isClicked(event, window))
        {
          hero_list[heroNo]->defeat(monster_list, *this, window);
          hero_list[heroNo]->set_action(hero_list[heroNo]->get_action() - 1);
        }
        if (advance.isClicked(event, window))
        {
          hero_list[heroNo]->advance(monster_list, *this, window, vec);
          hero_list[heroNo]->set_action(hero_list[heroNo]->get_action() - 1);
        }
        if (pickup.isClicked(event, window))
        {
          hero_list[heroNo]->pickup(window, *this);
          hero_list[heroNo]->set_action(hero_list[heroNo]->get_action() - 1);
        }
        if (guide.isClicked(event, window))
        {
          hero_list[heroNo]->guide(my_map, *this, window, *this);
          hero_list[heroNo]->set_action(hero_list[heroNo]->get_action() - 1);
        }
        if (perks.isClicked(event, window))
        {

          hero_list[heroNo]->use_perk(*this, window);
        }
        if (items.isClicked(event, window))
        {
          showCenteredTextBox(window, "you have this items :");
          for (auto it : hero_list[heroNo]->get_items())
          {
            showAssetInBox(window, "../Horrified_Assets/Items/General", it->get_name() + ".png");
          }
          showCenteredTextBox(window, "you have this perks :");
          for (auto pe : hero_list[heroNo]->get_perks())
          {
            showAssetInBox(window, "../Horrified_Assets/Perk_Cards", pe->get_name() + ".png");
          }
        }
      }

      if (state == initstate::heroSelection1) // chosing hero
      {
        if (Mayor.isClicked(event, window) && !Mayor.get_status())
        {
          Nohero.push_back(0);
          state = initstate::heroSelection2;
          selectionNo = 1;

          hero_list.push_back(new class Mayor(5, list_of_location[10], list_of_perks));
          // for (auto i : hero_list)
          // {
          //   i->get_loc()->set_hero_list(i);
          // }
          Mayor.set_status(!Mayor.get_status());
        }
        if (Archaeologist.isClicked(event, window) && !Archaeologist.get_status())
        {
          Nohero.push_back(1);
          selectionNo = 1;

          state = initstate::heroSelection2;
          hero_list.push_back(new class Archaeologist(4, list_of_location[12], list_of_perks));
          // for (auto i : hero_list)
          // {
          //   i->get_loc()->set_hero_list(i);
          // }

          Archaeologist.set_status(!Archaeologist.get_status());
        }
        if (courier.isClicked(event, window) && !courier.get_status())
        {
          Nohero.push_back(2);
          selectionNo = 1;

          state = initstate::heroSelection2;
          hero_list.push_back(new class courier(4, list_of_location[5], list_of_perks));
          // for (auto i : hero_list)
          // {
          //   i->get_loc()->set_hero_list(i);
          // }

          courier.set_status(!courier.get_status());
        }
        if (scientist.isClicked(event, window) && !scientist.get_status())
        {
          Nohero.push_back(3);
          selectionNo = 1;

          state = initstate::heroSelection2;

          hero_list.push_back(new class scientist(4, list_of_location[3], list_of_perks));
          // for (auto i : hero_list)
          // {
          //   i->get_loc()->set_hero_list(i);
          // }
          scientist.set_status(!scientist.get_status());
        }
      }
      if (state == initstate::heroSelection2) // chosing hero
      {
        if (Mayor.isClicked(event, window) && !Mayor.get_status())
        {
          Nohero.push_back(0);
          state = initstate::playmenu;

          hero_list.push_back(new class Mayor(5, list_of_location[10], list_of_perks));
          for (auto i : hero_list)
          {
            i->get_loc()->set_hero_list(i);
          }

          Mayor.set_status(!Mayor.get_status());
        }
        if (Archaeologist.isClicked(event, window) && !Archaeologist.get_status())
        {
          Nohero.push_back(1);

          state = initstate::playmenu;
          hero_list.push_back(new class Archaeologist(4, list_of_location[12], list_of_perks));
          for (auto i : hero_list)
          {
            i->get_loc()->set_hero_list(i);
          }

          Archaeologist.set_status(!Archaeologist.get_status());
        }
        if (courier.isClicked(event, window) && !courier.get_status())
        {
          Nohero.push_back(2);

          state = initstate::playmenu;
          hero_list.push_back(new class courier(4, list_of_location[5], list_of_perks));
          for (auto i : hero_list)
          {
            i->get_loc()->set_hero_list(i);
          }
          courier.set_status(!courier.get_status());
        }
        if (scientist.isClicked(event, window) && !scientist.get_status())
        {
          Nohero.push_back(3);

          state = initstate::playmenu;
          hero_list.push_back(new class scientist(4, list_of_location[3], list_of_perks));
          for (auto i : hero_list)
          {
            i->get_loc()->set_hero_list(i);
          }

          scientist.set_status(!scientist.get_status());
        }
      }

      if (event.type == sf::Event::Closed)
      {//sdfsdfsdsdf
        if (state == initstate::playmenu)
        {
          string folder;
          char detector;
          detector = tolower(showTextInputBox(window, "do you want to save the game ? y:yes  n:no")[0]);
          if (detector == 'y')
          {
            folder = show_folder_save(window);
            this->save_game("../save" + folder,vec);
          }

          window.setActive(false);
          window.close();
        }
        // need to check logic
      }
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
    if (state == initstate::showmonstercard)
    {
      back.draw(window);
      for (int i = 0; i < monster_card_list.size(); i++)
      {
        sf::Texture texture;
        if (!texture.loadFromFile("../Horrified_Assets/Monster_Cards/" + monster_card_list[i]->getName() + ".png"))
          throw out_of_range("couldnt find " + monster_card_list[i]->getName());

        sf::Sprite monster_c(texture);
        monster_c.setScale({200.f / texture.getSize().x, 300.f / texture.getSize().y});
        monster_c.setPosition((i % 7) * 250.f, (i / 7) * 300.f);
        window.draw(monster_c);
      }
    }
    if (state == initstate::showitemlocation)
    {
      renderItem(list_of_location[locationshow], window);
      back.draw(window);
    }
    if (state == initstate::heroSelection1 || state == initstate::heroSelection2)
    {
      massage massage({700, 250}, usersinfo[selectionNo].first + " please select your hero", sf::Color::Red, 40);
      massage.draw(window);
      if (!Mayor.get_status())
        Mayor.draw(window);
      if (!Archaeologist.get_status())
        Archaeologist.draw(window);
      if (!courier.get_status())
        courier.draw(window);
      if (!scientist.get_status())
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

      for (int i = 0; i < hero_list.size(); ++i)
      {
        sf::Texture texture;
        if (!texture.loadFromFile("../Horrified_Assets/Heros/" + hero_list[i]->get_hero_name() + ".png"))
          throw out_of_range("coulnt load " + hero_list[i]->get_hero_name() + ".png");

        int locId = hero_list[i]->get_loc()->get_loc_relation();
        sf::Sprite heroSprite(texture);
        heroSprite.setScale(100.f / texture.getSize().x, 135.f / texture.getSize().y);
        heroSprite.setPosition(locationPositions[locId].x,
                               locationPositions[locId].y);
        window.draw(heroSprite);
        // Draw hero name below the icon
      }
      monsterCard.draw(window);
      for (auto &&monster : monster_list)
      {
        sf::Sprite m, f;
        sf::Texture texture;

        if (typeid(*monster).name() == typeid(Drakula).name())
        {
          texture.loadFromFile("../Horrified_Assets/Monsters/Dracula.png");
          m.setTexture(texture);
          if (monster->get_is_frenzy())
            f.setTexture(texture);
        }
        if (typeid(*monster).name() == typeid(invisible_man).name())
        {
          texture.loadFromFile("../Horrified_Assets/Monsters/InvisibleMan.png");
          m.setTexture(texture);
          if (monster->get_is_frenzy())
            f.setTexture(texture);
        }
        m.setScale({66.666f / texture.getSize().x, 100.f / texture.getSize().y});
        if (monster->get_is_frenzy())
        {

          window.draw(FrenzyMonster);
          f.setScale({200.f / texture.getSize().x, 300.f / texture.getSize().y});
          f.setPosition({1600, 700});
          window.draw(f);
        }
        int locId = monster->get_loc()->get_loc_relation();

        m.setPosition(locationPositions[locId].x,
                      locationPositions[locId].y);
        window.draw(m);
      }

      // Draw each hero at their current location

      for (int i = 0; i < location_Button.size(); i++)
      {
        if (i == 1 || i == 7 || i == 16 || i == 17)
        {
          sf::Texture texture;
          sf::Sprite coffin;
          if (list_of_location[i]->get_coffin_exist())
          {
            if (!texture.loadFromFile("../Horrified_Assets/Items/Coffins/Coffin.png"))
              throw out_of_range("couldnt open Coffin.png");
          }
          else
          {
            if (!texture.loadFromFile("../Horrified_Assets/Items/Coffins/SmashedCoffin.png"))
              throw out_of_range("couldnt open SmashedCoffin.png");
          }
          coffin.setTexture(texture);
          coffin.setScale({75.f / texture.getSize().x, 50.f / texture.getSize().y});
          coffin.setPosition(locationPositions[i].x, locationPositions[i].y);

          window.draw(coffin);
        }
        for (auto &villager : list_of_location[i]->get_villager_list())
        {
          sf::Texture texture;
          sf::Sprite villagerSprite;
          if (!texture.loadFromFile("../Horrified_Assets/Villager/" + villager->get_name() + ".png"))
            throw out_of_range("couldnt find villager asset");
          villagerSprite.setTexture(texture);
          villagerSprite.setPosition(locationPositions[villager->get_currnet_location()->get_loc_relation()].x - 40, locationPositions[villager->get_currnet_location()->get_loc_relation()].y - 150);
          villagerSprite.setScale({200.f / texture.getSize().x, 300.f / texture.getSize().y});
          window.draw(villagerSprite);
        }
        window.draw(location_Button[i]);
      }
      sf::Texture texture;
      if (!texture.loadFromFile("../Horrified_Assets/Heros/" + hero_list[heroNo]->get_hero_name() + ".png"))
        throw out_of_range("coulnt load " + hero_list[heroNo]->get_hero_name() + ".png");
      sf::Sprite her(texture);
      her.setPosition({100, 25});
      her.setScale({200.f / texture.getSize().x, 300.f / texture.getSize().y});
      window.draw(her);

      // action info
      massage massageaction({100, 950}, "Reamaining action is " + to_string(hero_list[heroNo]->get_action()), sf::Color::White, 30);
      massageaction.draw(window);
      // loading night terror asset in map
      sf::Texture NightTerrorTexture;
      if (!NightTerrorTexture.loadFromFile("../Horrified_Assets/NightTerrorLevel.png"))
        throw out_of_range("coulnt find the NightTerrorLevel.png");
      sf::Sprite NightTerrorSprite(NightTerrorTexture);
      NightTerrorSprite.setScale({75.f / NightTerrorTexture.getSize().x, 75.f / NightTerrorTexture.getSize().y});
      NightTerrorSprite.setPosition(445.f + this->get_night_terror() * 60.f, 0);

      window.draw(NightTerrorSprite);
      invisiblemanMat.draw(window);
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

  return;
}