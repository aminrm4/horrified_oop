#include "monster_card.hpp"
#include "programm.hpp"
#include "monster.hpp"
#include "item.hpp"
#include <algorithm>
#include <random>
int random_number(int min, int max);

void remove_villager(programm &obj, villager *v);

int monster_card::get_item_count()
{
    return item_count;
}
void monster_card::_strike(int dice_attack, int move, programm &bug, monster *monsters)
{

    vector<vector<int>> routes;
    for (int i = 0; i < bug.list_of_location.size(); i++)
    {
        for (auto vill : bug.list_of_location.at(i)->get_villager_list())
        {
            routes.push_back(bug.bfs(monsters->get_loc()->get_loc_relation(), vill->get_currnet_location()->get_loc_relation()));
        }
    }
    for (int i = 0; i < bug.list_of_location.size(); i++)
    {
        for (auto hero : bug.list_of_location.at(i)->get_hero_list())
        {
            routes.push_back(bug.bfs(monsters->get_loc()->get_loc_relation(), hero->get_loc()->get_loc_relation()));
        }
    }

    vector<int> route = *min_element(routes.begin(), routes.end(), [](vector<int> &a, vector<int> &b)
                                     { return a.size() < b.size(); });

    if (routes.size() != 0)
        monsters->move_to_place(route, move, bug);
    else
    {
        cerr << "error in monster strike when finding min move to place \n";
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distib(1, 6);

    for (int i = 0; i < dice_attack && !monsters->get_did_attack(); i++)
    {
        int rand = distib(gen);
        if (rand == 1) // power dice aval
        {
            cout << "dice rolled a power" << endl;
            vector<int> s;
            monsters->ability(bug);
        }

        rand = distib(gen);
        if (rand == 5 || rand == 5) // attack dice
        {
            if (!monsters->get_loc()->get_hero_list().empty())
            {
                cout << "dice rolled a attack" << endl;

                cout << "oh no a monster want to attack you Do you want to Defend your self ? [Y]es , [N]o \n";
                try
                {

                    char state;
                    cin >> state;
                    state = tolower(state);
                    if (state == 'y')
                    {
                        for (auto item : monsters->get_loc()->get_hero_list()[0]->get_items())
                        {
                            cout << item->get_name() << endl;
                        }
                        cout << "emter the name of your item \n";
                        string name;
                        cin >> name;
                        for (int i = 0; i < monsters->get_loc()->get_hero_list()[0]->get_items().size(); i++)
                        {
                            if (monsters->get_loc()->get_hero_list()[0]->get_items()[i]->get_name() == name)
                            {
                                delete monsters->get_loc()->get_hero_list()[0]->get_items()[i];
                                monsters->get_loc()->get_hero_list()[0]->get_items().erase(monsters->get_loc()->get_hero_list()[0]->get_items().begin(), monsters->get_loc()->get_hero_list()[0]->get_items().end());
                                return;
                            }
                        }
                        cout << "im sorry i couldnt find your item and monster attacked you and night terror level increasd \n";
                        monsters->get_loc()->get_hero_list()[0]->move(bug.list_of_location[0], bug);
                        bug.set_night_terror(bug.get_night_terror() + 1);
                        monsters->set_did_attack(true);

                        return;
                    }
                    if (state == 'n')
                    {
                        monsters->get_loc()->get_hero_list()[0]->move(bug.list_of_location[0], bug);
                        bug.set_night_terror(bug.get_night_terror() + 1);
                        monsters->set_did_attack(true);
                        cout << "the monster attakced you and i saved " << monsters->get_loc()->get_hero_list()[0]->get_hero_name() << "now you are in hospital \n";
                        return;
                    }

                    throw invalid_argument("wrong charachter\n");
                }
                catch (const std::exception &e)
                {
                    cout << e.what();
                }

                return;
            }

            if (!monsters->get_loc()->get_villager_list().empty())
            {
                monsters->set_did_attack(true);
                remove_villager(bug, monsters->get_loc()->get_villager_list()[0]);
                delete monsters->get_loc()->get_villager_list()[0]->drop_the_perk();
                delete monsters->get_loc()->get_villager_list()[0];
                bug.set_night_terror(bug.get_night_terror() + 1);
                cout << "a villager has been killed by a monster and night terror level increased \n";
                return;
            }
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
