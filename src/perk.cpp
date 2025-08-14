#include "perk.hpp"
#include "programm.hpp"
using namespace std;
namespace fs = filesystem;
string perk::get_name()
{
    return name;
}
void perk::save_game(const string file_name)
{

    ofstream data_saver(file_name, ios::app);
    if (!data_saver)
    {
        cerr << "perk file can not be opend" << endl;
    }

    data_saver << name << endl;
}
void perk::load_game(std::string file_name, programm &bug)
{
    fs::path dir = file_name;
    file_name = dir / "perks.txt";
    ifstream loader(file_name);
    if (!loader)
    {
        throw invalid_argument("perks file could not be opend");
    }
    string nam;
    int counter = 0;

    while (loader >> nam)
    {
        counter++;
        for (int i = 0; i < bug.list_of_perks.size(); i++)
        {
            if (bug.list_of_perks[i]->get_name() == nam)
            {
                rotate(bug.list_of_perks.begin(), bug.list_of_perks.begin() + i, bug.list_of_perks.begin() + i + 1);
                break;
            }
        }
    }
    bug.list_of_perks.erase(bug.list_of_perks.begin() + counter, bug.list_of_perks.end());
    loader.close();
    for (auto pp : bug.list_of_perks)
    {
        cout << pp->get_name() << endl;
    }
}
