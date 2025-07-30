#include "The_Delivery.hpp"

void The_Delivery::event(std::vector<std::vector<int>>& map,std::vector<location*>& loc , programm& a)
{
    a.list_of_location[12]->set_villager((new villager("WilburAndChick", loc[16], loc[12], a)));

    cout << "Chick_&_Wilbur sommend in docks go and help him \n";
}
void The_Delivery::monster_strike(programm &bug, vector<monster *> &monsters)
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if (monsters[i]->get_freenzy_status())
            monster_card::_strike(dice_play, move_left, bug, monsters[i]);
    }
}
void The_Delivery::set_item(int item_count)
{
    this->item_count = item_count;
}
   The_Delivery:: The_Delivery(int dic,int my_item,int mover)
    {
        dice_play=dic;
        item_count=my_item;
        move_left=mover;
        this->name_of_card="TheDelivery";
    }
