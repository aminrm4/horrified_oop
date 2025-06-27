#include "Color.hpp"
namespace rgb
{
std::ostream& operator<<(std::ostream& output , rgb::Color  color) //does it need pass by refrence?
{
    switch (color)
    {

        case rgb::Color::Red :
            output << "Red";
        break;
    
        case rgb::Color::Yellow :
            output << "Yellow";
        break;
    
        case rgb::Color::Blue :
            output << "Blue";
        break;
        
        default:
            break;
    }
    return output;
}
}