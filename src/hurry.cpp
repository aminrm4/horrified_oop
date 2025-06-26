#include <iostream>
#include "hurry.hpp"
#include "programm.hpp"
#include <iostream>
using namespace std;
void hurry::play(hero *he, std::vector<hero *> &he_list, monster *mo, std::vector<location *> & loc, std::vector<item *>  &it_list, std::vector<monster *> & mo_list, programm & help_obj1)
{
    //fake vill
   
    for (size_t i = 0; i < 2; i++)
    {
        cout << "enter the place wich you want to move the" << i << "hero :" << endl;
        int id;
        cin >> id;
        if (id < 0 || id > 18)
        {
            throw invalid_argument("the location does not exist \n");
        }

        int direct = he_list[i]->get_loc()->get_loc_relation();
        help_obj1.bfs(direct, id);
        if (!(he_list[i]->get_loc()->get_villager_list().empty()))
        {
            cout << " ohhhhhh, there are some villager in your position , would you like to help them \n";
            char right;
            cin.get(right);
            if (right == 'yes')
            {
                auto it =he_list[i]->get_loc()->get_villager_list();//force to do
                he_list[i]->move(loc[id],it);
                break;
            }
            else
            {
                he_list[i]->move(loc[id]);
                break;
            }
        }
        else
        {
                    he_list[i]->move(loc[id]);

        }
        
    }
}
