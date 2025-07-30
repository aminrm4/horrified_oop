#include "Mayor.hpp"
#include"SFML/Graphics.hpp"
#include"free_func.hpp"
using namespace std;

void Mayor::special_action(std::vector<std::vector<int>> &map,programm & bug,sf::RenderWindow & window)
{
    showCenteredTextBox(window,"you dont have sepcial action haaa");
}
Mayor::Mayor(int actions, location *starting_loc, std::vector<perk *> &perks) : hero(perks)
{
    name_of_hero = "Mayor";
    if (actions < 0)
        throw logic_error("invalid actions \n");
    action = actions;

    loc = starting_loc;
}