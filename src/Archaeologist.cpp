#include "Archaeologist.hpp"
using namespace std;
void Archaeologist::special_action(vector<vector<int>> &map, const vector<location *> &loc)
{
    int node_number = this->get_loc()->get_loc_relation();

    cout << "select one location to pick item from \n";
    for (auto node_connected : map[node_number])
        cout << node_connected << ' ';
    cout << endl;

    try
    {

        int node;
        cin >> node;
        bool is_connected{};
        for (auto node_connected : map[node_number])
            if (node == node_connected)
                is_connected = true;

        if (is_connected)
        {
            for (auto locations : loc)
                if (locations->get_loc_relation() == node)
                {
                    vector<item *> items(locations->get_item_list());
                       
                    if (items.empty())
                    {
                        cout<<"ohhhhh my bad there was nothing"<<endl;
                        return;
                    }
                    
                    cout << "you picked these items :\n";
                    for (auto it : items)
                        cout << it->get_name() << endl;

                    cout << endl;
                    this->item_have.insert(item_have.end(), items.begin(), items.end());

                    locations->get_item_list().clear();
                }
        }
        else
        {
            throw logic_error("the node you selected is too far \n");
        }
    }
    catch (logic_error &e)
    {
        cout << e.what();
        special_action(map, loc);
        return;
    }
}
Archaeologist::Archaeologist(int actions, location *starting_loc, std::vector<perk *> &perks) : hero(perks)
{
    if (actions < 0)
        throw logic_error("invalid actions \n");
    action = actions;
    swap(loc, starting_loc);
    name_of_hero = "archaeologist";
}
