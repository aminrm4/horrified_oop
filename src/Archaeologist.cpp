#include "Archaeologist.hpp"
#include "programm.hpp"
#include "free_func.hpp"
using namespace std;
void Archaeologist::special_action(std::vector<std::vector<int>> &map, programm &bug, sf::RenderWindow &window)
{
    int node_number = this->get_loc()->get_loc_relation();

    showCenteredTextBox(window, "selec a location to pick item from");

    try
    {
        int node;
        node = showLocationTextBox(window,bug,*this);
        if (node<0)
        {
            showCenteredTextBox(window,"ohhh you exit the special action");
            return;
        }
        
        bool is_connected{};
        for (auto node_connected : map[node_number])
            if (node == node_connected)
                is_connected = true;

        if (is_connected)
        {
            for (auto locations : bug.list_of_location)
                if (locations->get_loc_relation() == node)
                {
                    vector<item *> items(locations->get_item_list());

                    if (items.empty())
                    {
                        showCenteredTextBox(window, "ohh my bad there was nothing there");
                        return;
                    }

                    showCenteredTextBox(window, "you picked up these items ");
                    for (auto it : items)
                    showAssetInBox(window,"../Horrified_Assets/Items/General",it->get_name()+".png");

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
        showCenteredTextBox(window,"the node you selected is too far");
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
