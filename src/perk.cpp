#include "perk.hpp"
using namespace std;
string perk::get_name()
{
    return name;
}
void perk::save_game(const string file_name)
{

    ofstream data_saver(file_name,ios::app);
    if (!data_saver)
    {
        cerr << "perk file can not be opend" << endl;
    }



    data_saver<<name<<endl;
}
