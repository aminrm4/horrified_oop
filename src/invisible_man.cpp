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