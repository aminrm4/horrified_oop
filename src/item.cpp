#include "item.hpp"
#include <exception>
#include <fstream>
#include "location.hpp"
#include "programm.hpp"
using namespace std;
namespace fs = filesystem;
item::item(int power, std::string name, rgb::Color color, location *loc)
{
    if (power <= 0)
        throw std::logic_error("invalid power \n");

    this->power = power;
    this->name = name;
    this->color = color;
    this->loc = loc;
}
int item::get_power()
{
    return power;
}
std::string item::get_name()
{
    return name;
}
rgb::Color item::get_Color()
{
    return color;
}

location *item::get_loc()
{
    return loc;
}

ostream &operator<<(ostream &output, item &i)
{
    return output << i.get_name() << ' ' << i.get_power() << ' ' << i.get_Color();
}
item::~item()
{
    loc = nullptr;
}
void item::save_game(const string file_name)
{
    ofstream data_saver(file_name, ios::app);
    if (!data_saver)
    {
        cerr << "item file can not be opend" << endl;
    }

    data_saver << name << " " << endl;
}
void item::load_game(std::string file_name, programm &bug)
{
    fs::path dir = file_name;
    file_name = dir / "items.txt";
    ifstream loader(file_name);
    if (!loader)
    {
        cerr << "item file can not load" << endl;
    }
    int counter = 0;
    string nam;
    while (loader >> nam)
    {
        counter++;
        for (int i = 0; i < bug.list_of_items.size(); i++)
        {
            if (bug.list_of_items[i]->get_name() == nam)
            {
                rotate(bug.list_of_items.begin(), bug.list_of_items.begin() + i, bug.list_of_items.begin() + i + 1);
                break;
            }
        }
    }
    bug.list_of_items.erase(bug.list_of_items.begin() + counter, bug.list_of_items.end());
    loader.close();
}
    void  item::set_power(int pow)
    {
            this->power=pow;
    }
