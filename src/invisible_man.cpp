#include "Invisible_man.hpp"
using namespace std;
void invisible_man::set_remain_hidden_item(int r)
{
    remain_hidden_item = r;
}
int invisible_man::get_remain_hidden_item()
{
    return remain_hidden_item;
}
void invisible_man::ability(std::vector <int> & route , vector<location*> & locations , hero* h)
{
    cout << "invisible man used his ability and moved 2 place \n";
    this->move_to_place(route , 2 , locations);
}
invisible_man::invisible_man(int remain_hidden_item, bool is_freenzy ,int freenzy_order,location* loc)
{
    if(remain_hidden_item < 0 || freenzy_order < 0)
    throw invalid_argument("invalid remain_hidden_item or freenzy_order \n");

    this->remain_hidden_item = remain_hidden_item;
    this->freenzy_order = freenzy_order;
    this->is_freenzy = is_freenzy;
    this->loc = loc;
    name_of_monster="Invisible_man";

}
