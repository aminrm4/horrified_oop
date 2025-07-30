#include "monster_card.hpp"
#include "programm.hpp"
#include "monster.hpp"
#include "Button.hpp"
#include "massage.hpp"
#include "item.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <random>
#include "Button2.hpp"
namespace fs = std::filesystem;
int random_number(int min, int max);

void remove_villager(programm &obj, villager *v);

int monster_card::get_item_count()
{
    return item_count;
}
void monster_card::_strike(int dice_attack, int move, programm &bug, monster *monster)
{

    // move
    vector<vector<int>> routes;
    for (int i = 0; i < bug.list_of_location.size(); i++)
    {
        for (auto vill : bug.list_of_location.at(i)->get_villager_list())
        {
            routes.push_back(bug.bfs(monster->get_loc()->get_loc_relation(), vill->get_currnet_location()->get_loc_relation()));
        }
    }
    for (int i = 0; i < bug.list_of_location.size(); i++)
    {
        for (auto hero : bug.list_of_location.at(i)->get_hero_list())
        {

            routes.push_back(bug.bfs(monster->get_loc()->get_loc_relation(), hero->get_loc()->get_loc_relation()));
        }
    }
    vector<int> route = *min_element(routes.begin(), routes.end(), [](vector<int> &a, vector<int> &b)
                                     { return a.size() < b.size(); });

    if (routes.size() != 0)
        monster->move_to_place(route, move, bug);
    else
    {
        cerr << "error in monster strike when finding min move to place \n";
    }
    // strike
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distib(1, 6);

    vector<pair<Button2, item *>> Buttonitem;
    for (int i = 0; i < dice_attack && !monster->get_did_attack(); i++)
    {
        int rand = distib(gen);
        if (rand == 1) // power dice aval
        {
            cout << "dice rolled a power" << endl;
            vector<int> s;
            monster->ability(bug);
        }

        rand = distib(gen);
        rand = 3;
        if (rand == 5 || rand == 3) // attack dice
        {
            enum State
            {
                info,
                yes,
                no
            };
            State state = State::info;
            if (!monster->get_loc()->get_hero_list().empty()) // fixe
            {
                for (int i = 0; i < monster->get_loc()->get_hero_list()[0]->get_items().size(); i++)
                {
                    string dir = "../Horrified_Assets/Items/";
                    switch (monster->get_loc()->get_hero_list()[0]->get_items()[i]->get_Color())
                    {
                    case rgb::Color::Red:
                        dir += "Red/";
                        break;
                    case rgb::Color::Yellow:
                        dir += "Yellow/";
                        break;
                    case rgb::Color::Blue:
                        dir += "Blue/";
                        break;
                    }
                    dir += monster->get_loc()->get_hero_list()[0]->get_items()[i]->get_name();
                    Buttonitem.push_back({Button2({200, 100}, {(i % 6) * 300.f, (i / 6) * 200.f}, dir), monster->get_loc()->get_hero_list()[0]->get_items()[i]});
                }

                massage m({400, 400}, monster->get_mons_name() + " Want to attack " + monster->get_loc()->get_hero_list()[0]->get_hero_name() + "do you want to defend your self ?", sf::Color::Red, 40);
                Button Yes({200.f, 100.f}, {400, 600}, "Yes");
                Button No({200.f, 100.f}, {700, 600}, "No");

                sf::Texture texture;
                if (!texture.loadFromFile("../Horrified_Assets/monster_.png"))
                    throw out_of_range("cant load MonserPhaseBG.png");

                sf::Sprite Bg(texture);
                Bg.setScale(1920.f / texture.getSize().x, 1080.f / texture.getSize().y);

                sf::RenderWindow window({1920, 1080}, "Monster Strike");
                while (window.isOpen())
                {
                    sf::Event event;
                    while (window.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed) // fix here
                            window.close();
                        if (state == State::info)
                        {
                            if (Yes.isClicked(event, window))
                            {
                                if (!monster->get_loc()->get_hero_list().empty())
                                    state = State::no;
                                else
                                    state = State::yes;
                            }
                            if (No.isClicked(event, window))
                            {
                                state = State::no;
                            }
                        }
                        if (state == State::yes)
                        {
                            for (int i = 0; i < Buttonitem.size(); i++)
                            {
                                if (Buttonitem[i].first.isClicked(event, window))
                                {
                                    delete monster->get_loc()->get_hero_list()[0]->get_items()[i];
                                    monster->get_loc()->get_hero_list()[0]->get_items().erase(monster->get_loc()->get_hero_list()[0]->get_items().begin() + i);
                                    window.close();
                                    return;
                                }
                            }
                        }
                        if (state == State::no)
                        {
                            bug.set_night_terror(bug.get_night_terror() + 1);
                            monster->get_loc()->get_hero_list()[0]->move(bug.list_of_location[0], bug);
                            monster->set_did_attack(true);
                            window.close();
                            return;
                        }
                    }
                    window.clear();
                    window.draw(Bg);
                    if (state == State::info)
                    {
                        Yes.draw(window);
                        No.draw(window);
                        m.draw(window);
                    }
                    if (state == State::yes)
                    {
                        for (auto &&Button : Buttonitem)
                        {
                            Button.first.draw(window);
                        }
                    }

                    window.display();
                }
            }
            if (!monster->get_loc()->get_villager_list().empty())
            {
                monster->set_did_attack(true);
                remove_villager(bug, monster->get_loc()->get_villager_list()[0]);
                delete monster->get_loc()->get_villager_list()[0]->drop_the_perk();
                delete monster->get_loc()->get_villager_list()[0];
                bug.set_night_terror(bug.get_night_terror() + 1);
                cout << "a villager has been killed by a monster and night terror level increased \n";
                return;
            }

            //     cout << "dice rolled a attack" << endl;

            //     try
            //     {

            //         char state;
            //         cin >> state;
            //         state = tolower(state);
            //         if (state == 'y')
            //         {
            //             for (auto item : monster->get_loc()->get_hero_list()[0]->get_items())
            //             {
            //                 cout << item->get_name() << endl;
            //             }
            //             cout << "emter the name of your item \n";
            //             string name;
            //             cin >> name;
            //             for (auto he : monster->get_loc()->get_hero_list())
            //             {
            //                 if (he->get_hero_name() == "scientist")
            //                 {
            //                     he->ability(name);
            //                     break;
            //                 }
            //             }

            //             for (int i = 0; i < monsters->get_loc()->get_hero_list()[0]->get_items().size(); i++)
            //             {
            //                 if (monsters->get_loc()->get_hero_list()[0]->get_items()[i]->get_name() == name)
            //                 {
            //                     delete monsters->get_loc()->get_hero_list()[0]->get_items()[i];
            //                     monsters->get_loc()->get_hero_list()[0]->get_items().erase(monsters->get_loc()->get_hero_list()[0]->get_items().begin() + i);
            //                     return;
            //                 }
            //             }
            //             cout << "im sorry i couldnt find your item and monster attacked you and night terror level increasd \n";
            //             monsters->get_loc()->get_hero_list()[0]->move(bug.list_of_location[0], bug);
            //             bug.set_night_terror(bug.get_night_terror() + 1);
            //             monsters->set_did_attack(true);

            //             return;
            //         }
            //         if (state == 'n')
            //         {
            //             cout << "the monster attakced you and i saved " << monsters->get_loc()->get_hero_list()[0]->get_hero_name() << "now you are in hospital \n";
            //             monsters->get_loc()->get_hero_list()[0]->move(bug.list_of_location[0], bug);
            //             bug.set_night_terror(bug.get_night_terror() + 1);
            //             monsters->set_did_attack(true);
            //             return;
            //         }

            //         throw invalid_argument("wrong charachter\n");
            //     }
            //     catch (const std::exception &e)
            //     {
            //         cout << e.what();
            //     }

            //     return;
            // }

            // if (!monsters->get_loc()->get_villager_list().empty())
            // {
            //     monsters->set_did_attack(true);
            //     remove_villager(bug, monsters->get_loc()->get_villager_list()[0]);
            //     delete monsters->get_loc()->get_villager_list()[0]->drop_the_perk();
            //     delete monsters->get_loc()->get_villager_list()[0];
            //     bug.set_night_terror(bug.get_night_terror() + 1);
            //     cout << "a villager has been killed by a monster and night terror level increased \n";
            //     return;
            // }
        }
    }
}
int monster_card::get_dice_play()
{
    return dice_play;
}
int monster_card::get_move_count()
{
    return move_left;
}
void monster_card::item_handler(programm &help_object)
{
    for (int i = 0; i < item_count; i++)
    {

        int random = random_number(0, help_object.list_of_items.size() - 1);
        help_object.list_of_items.at(random)->get_loc()->set_item_list(help_object.list_of_items.at(random));
        help_object.list_of_items.erase(help_object.list_of_items.begin() + random);
    }
}
void monster_card::save_game(const string file_name)
{
    ofstream data_saver(file_name, ios::app);
    if (!data_saver)
    {
        cerr << "monster_card file can not be opend" << endl;
    }
    data_saver << name_of_card << endl;
}
void monster_card::load_game(std::string file_name, programm &bug)
{
    int counter = 0;
    fs::path dir = file_name;
    file_name = dir / "monster_card.txt";
    ifstream loader(file_name);
    if (!loader)
    {
        cerr << "monster_card file could not load" << endl;
    }
    string name_card;
    while (loader >> name_card)
    {
        counter++;
        for (int i = 0; i < bug.monster_card_list.size(); i++)
        {
            if (bug.monster_card_list[i]->name_of_card == name_card)
            {
                rotate(bug.monster_card_list.begin(), bug.monster_card_list.begin() + i, bug.monster_card_list.begin() + i + 1);
                break;
            }
        }
    }
    bug.monster_card_list.erase(bug.monster_card_list.begin() + counter, bug.monster_card_list.end());
    loader.close();
}
