#include "The_chthyologist.hpp"

void The_chthyologist::event(std::vector<std::vector<int>>& map,std::vector<location*>& loc , programm& a)
{
    cout << "Dr.Reed sommend in institute go and help him \n";
    a.list_of_location[3]->set_villager((new villager("DrReed", loc[18], loc[3], a)));
}
void The_chthyologist::monster_strike(programm &bug, vector<monster *> &monsters)
{
    for (int i = 0; i < monsters.size(); i++)
    {
        if (monsters[i]->get_freenzy_status())
            monster_card::_strike(dice_play, move_left, bug, monsters[i]);
    }
}
void The_chthyologist::set_item(int item_count)
{
    this->item_count = item_count;
}
   The_chthyologist:: The_chthyologist(int dic,int my_item,int mover)
    {
        dice_play=dic;
        item_count=my_item;
        move_left=mover;
        this->name_of_card="The_chthyologist";
    }
