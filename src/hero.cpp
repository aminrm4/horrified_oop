#include "hero.hpp"
#include <stdexcept>
using namespace std;

void hero::move(location* loc , vector<villager*>villagers = {} )
{
    this->loc = loc;
    if(!villagers.empty())
    {
        cout << "Do you want to move villagers with you ? \n [Y]es \n [N]o \n Enter a character \n";
        try
        {
            char status;
            cin >>status;
            status = tolower(status);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            if(status != 'y' && status!= 'n')
            throw logic_error("invalid Character \n");
            
            if(status == 'y')
                for(auto v : villagers)
                    v->set_current_location(this->loc);

        }
        catch(logic_error &e)
        {
            cout << e.what();
            cout << "try again\n";
            hero::move(loc ,villagers);
        }

    }
}
void hero::guide(vector<vector<int>> map )
{
    int thisNumLoc = this->loc->get_loc_relation();
    for(auto related_node : map[thisNumLoc])
        cout<<related_node<<' ';
    cout << "\n select the location to see witch villagers are there and you want to guide them\n";
    try
    {
        int node_number;
        cin >> node_number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        bool is_connected {};

        for(auto node : map[node_number])
            if(node == thisNumLoc)
                is_connected =true;

        if(is_connected)
        {

        }
        else
        {
            throw logic_error("the location that you selected is far away \n");
            guide(map);
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        guide(map);

    }
    

}
void hero::advance()
{
    cout << "pls select a monster \n [D]rakula \n [I]nvisible man \n";
    try
    {
        char m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        m = tolower(m);
        if(m != 'd' || m != 'i')
            {
                throw logic_error("Worng character \n");
                advance();
            }
        switch (m)
        {
            case 'i':
                cout << "For defeating this monster you must find 5 evidence and put them in precinct\n";
                if((this->get_loc()) ) // fix here
                {
                    cout << "you can select some item u put down in here \n";
                }
                else
                {
                    cout << "you cant put down any item";
                }

            break;


            case 'd':
                cout << "For deafeting Drakula you must destroy his coffin's \n";
                if(this->get_loc()) //fix here
                {

                }
                else
                {
                    cout << "There is not any coffin here \n";
                }
                break;
        
        
        
            default:
                break;
        }

    }
    catch(const logic_error& e)
    {
        std::cerr << e.what() << '\n';
        advance();
    }
    catch(invalid_argument &e)
    {
        cerr<<e.what();
        advance();
    }
    
}