#include "Archaeologist.hpp"
using namespace std;
void Archaeologist::special_action(vector<vector<int>>& map , vector<location*> loc)
{
    int node_number = this->get_loc()->get_loc_relation();

    cout << "select one location to pick item from \n";
    for(auto node_connected : map[node_number])
    cout << node_connected << ' ';

    try
    {
        int node ;
        cin >> node;
        bool is_connected {};
        
        for(auto node_connected : map[node_number])
            if(node == node_connected )
                is_connected = true;
    
    
        if(is_connected)
        {
            for(auto locations : loc)
                if(locations->get_loc_relation() == node)
                    {//locations-> need itemlist geter 
                    ;
                    // need fix
                    //this->item_have.insert()
                }
        }
        else
        {
            throw logic_error("the node you selected is too far \n");
        }

        
   }
   catch(logic_error &e)
   {
    cout << e.what();
   }


}