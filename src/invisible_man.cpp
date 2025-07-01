#include "Invisible_man.hpp"
#include "programm.hpp"
using namespace std;

void invisible_man::ability(programm & bug)
{
        vector<vector<int>> routes;
    for(int i =0; i < bug.list_of_location.size();i++)
    {
        for (auto vill : bug.list_of_location.at(i)->get_villager_list())
        {
            routes.push_back(bug.bfs(this->get_loc()->get_loc_relation() , vill->get_currnet_location()->get_loc_relation()));
        }
        
    }

    vector<int> route = *min_element(routes.begin() , routes.end() ,[](vector<int>& a , vector<int>& b){
        return a.size() < b.size();
    });

    if(routes.size() != 0)
    this->move_to_place( route, 2, bug);
    else
    {
        cerr << "error in monster strike when finding min move to place \n";
    }
    cout << "invisible man used his ability and moved 2 place \n";

}
invisible_man::invisible_man(int remain_hidden_item, bool is_freenzy ,int freenzy_order,location* loc)
{
    if(remain_hidden_item < 0 || freenzy_order < 0)
    throw invalid_argument("invalid remain_hidden_item or freenzy_order \n");

    this->totla_hidden_item=remain_hidden_item;
    this->freenzy_order = freenzy_order;
    this->is_freenzy = is_freenzy;
    this->loc = loc;
    name_of_monster="Invisible_man";

}
