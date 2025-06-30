#include "monster_card.hpp"
#include "programm.hpp"
#include "monster.hpp"
#include "item.hpp"
#include <algorithm>
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
    cout << "kkpppppk \n";

    vector<int> route = *min_element(routes.begin(), routes.end(), [](vector<int> &a, vector<int> &b)
                                     { return a.size() < b.size(); });

    cout << "kkpppppk \n";
    if (routes.size() != 0)
        monsters->move_to_place(route, move, bug.list_of_location, bug);
    else
    {
        cerr << "error in monster strike when finding min move to place \n";
    }
    cout << "kkkk \n";
  
    for (int i = 0; i < dice_attack && !monsters->get_did_attack(); i++)
    {
        auto now = std::chrono::system_clock::now();
        auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
      

        srand(millis);
        int rand = random() % 6;
        cin.get();
        cout << rand;
        if (rand == 1) // power dice aval
        {
            vector<int> s;
            monsters->ability(s, bug, bug.list_of_location, nullptr);
        }
   

        now = std::chrono::system_clock::now();
        millis = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
   
        srand(millis);
        rand = random() % 6;
           cin.get();
        cout << rand;
        if (rand == 3) // power dice 2
        {
            vector<int> s;
            monsters->ability(s, bug, bug.list_of_location, nullptr);
        }
   

        now = std::chrono::system_clock::now();
        millis = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

        srand(millis);
        rand = random() % 6;
        cin.get();
        cout << rand;
        if (rand == 5) // attack dice
        {
            if (!monsters->get_loc()->get_hero_list().empty())
            {
                cout << "oh no a monster want to attack you Do you want to Defend your self ? [Y]es , [N]o \n";
                try
                {
                    cin.clear();
                    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    char state;
                    cin >> state;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
                            if (monsters->get_loc()->get_hero_list()[0]->get_items()[i]->get_name() == name) // here has a problem
                            {
                                delete monsters->get_loc()->get_hero_list()[0]->get_items()[i];
                                monsters->get_loc()->get_hero_list()[0]->get_items().erase(monsters->get_loc()->get_hero_list()[0]->get_items().begin(), monsters->get_loc()->get_hero_list()[0]->get_items().end());
                                return;
                            }
                        }
                        cin.get();
                        cout << "im sorry i couldnt find your item and monster attacked you and night terror level increasd \n";
                        monsters->get_loc()->get_hero_list()[0]->move(bug.list_of_location[0], bug);
                        bug.set_night_terror(bug.get_night_terror() + 1);
                        monsters->set_did_attack(true);
                        cin.get();

                        return;
                    }
                    if (state == 'n')
                    {
                        monsters->get_loc()->get_hero_list()[0]->move(bug.list_of_location[0], bug);
                        bug.set_night_terror(bug.get_night_terror() + 1);
                        monsters->set_did_attack(true);
                        cout<< "the monster attakced you and i saved "<< monsters->get_loc()->get_hero_list()[0]->get_hero_name() <<"now you are in hospital \n";
                        return;
                    }

                    throw invalid_argument("wrong charachter\n");
                }
                catch (const std::exception &e)
                {

                    std::cerr << "nigga" << '\n';
                }

                // bug.set_night_terror(bug.get_night_terror()+1);
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
    //    programm p;
    //     monsters->move_to_place( route, move ,loc , bug);
    //     cout << "look a monster moved his place be careful \n";
    //     set<int> a = p.random_generator(1 , 36 , 1);
    //     set<int>::iterator it = a.begin();
    //     it++;

    // if(*it == 1)  // ability
    // {
    //     cout << "Oh no the monster want to use his ability a player \n";
    //     monsters->ability(route ,bug, loc, h);
    // }
    // if(*it == 2) // strike
    // {
    //     cout << "Oh no the monster want to strike !!! \n";
    //     vector<villager*> v = monsters->get_loc()->get_villager_list();
    //     if(!v.empty())
    //     {
    //         cout << "Oh noooooo all the villagers died ";
    //         cout << "RIP villager's \n";
    //         p.set_night_terror(p.get_night_terror() + v.size());
    //         monsters->get_loc()->delete_villager_list();
    //         return ;
    //     }
    //     vector<hero*> pp = monsters->get_loc()->get_hero_list();
    //     if(!pp.empty())
    //     {
    //         cout << "Oh no the monster reached you u must drop item u escape from monster strike \n";
    //         cout << "Do you want to do it ? [Y]es , [N]o";
    //         try
    //         {
    //             char status;
    //             cin >> status;
    //             cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //             status = tolower(status);
    //             if(status == 'y')
    //             {
    //                 int index;
    //                 cout << "enter the index of your item  " << typeid(*pp[0]).name() << endl;
    //                 cin >> index;
    //                 vector <item*> invo = pp[0]->get_items();
    //                 invo.erase(invo.begin());
    //                 pp[0]->set_item(invo);
    //                 return;
    //             }
    //             else
    //             {

    //                 cout << "you couldnt save your self but i managed to heal you and bring you to hospital \n";
    //                 p.set_night_terror(p.get_night_terror() + 1);
    //                 pp[0]->move(loc[0],bug);
    //             }

    //         }
    //         catch(const logic_error& e)
    //         {
    //             std::cerr << e.what() << '\n';

    //         }

    //     }
    //     cout << "tanks god he is far away \n";
    // }
}
