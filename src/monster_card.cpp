#pragma once
#include "monster_card.hpp"
#include "programm.hpp"
#include "monster.hpp"
int monster_card::get_item_count()
{
    return item_count;
}
void monster_card::monster_strike(int dice_attack,int move, monster* monsters , vector<int> & route , vector<location*>&loc , hero* h )
{
       programm p;
        monsters->move_to_place( route, move ,loc);
        cout << "look a monster moved his place be careful \n";
        set<int> a = p.random_generator(1 , 36 , 1);
        set<int>::iterator it = a.begin();
        it++;
        if(*it == 1)  // ability
        {
            cout << "Oh no the monster want to use his ability a player \n";
            monsters->ability(route , loc, h);
        }
        if(*it == 2) // strike
        {
            cout << "Oh no the monster want to strike !!! \n";
            vector<villager*> v = monsters->get_loc()->get_villager_list();
            if(!v.empty())
            {
                cout << "Oh noooooo all the villagers died ";
                cout << "RIP villager's \n";
                p.set_night_terror(p.get_night_terror() + v.size());
                monsters->get_loc()->delete_villager_list();
                return ;
            }
            vector<hero*> pp = monsters->get_loc()->get_hero_list();
            if(!pp.empty())
            {
                cout << "Oh no the monster reached you u must drop item u escape from monster strike \n";
                cout << "Do you want to do it ? [Y]es , [N]o";
                try
                {
                    char status;
                    cin >> status;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    status = tolower(status);
                    if(status == 'y')
                    {
                        int index;
                        cout << "enter the index of your item  " << typeid(*pp[0]).name() << endl;
                        cin >> index;
                        vector <item*> invo = pp[0]->get_items();
                        invo.erase(invo.begin());
                        pp[0]->set_item(invo);
                        return;
                    }
                    else
                    {
                        
                        cout << "you couldnt save your self but i managed to heal you and bring you to hospital \n";
                        p.set_night_terror(p.get_night_terror() + 1);
                        pp[0]->move(loc[0]);
                    }


                }
                catch(const logic_error& e)
                {
                    std::cerr << e.what() << '\n';

                }
                
            }
            cout << "tanks god he is far away \n";
        }
        
}
