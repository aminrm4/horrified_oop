#include "Mayor.hpp"
using namespace std;

void Mayor::special_action(std::vector<std::vector<int>> &map,programm & bug)
{
    cout << "you fooled you dont have any special action hahaha \n";
}
Mayor::Mayor(int actions, location *starting_loc, std::vector<perk *> &perks) : hero(perks)
{
    name_of_hero = "mayor";
    if (actions < 0)
        throw logic_error("invalid actions \n");
    action = actions;

    loc = starting_loc;
}