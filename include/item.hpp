#pragma
#include <string>
#include <Color.hpp>
class item
{
    int power ;
    std::string name;
    Color color;
    //loc * location;
    
    public:
    item(int , std::string , Color /*, loc* */);
    int get_power();
    std::string get_name();
    Color get_Color();
    //loc* get_loc();

};