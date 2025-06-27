#include "Color.hpp"

std::ostream& operator<<(std::ostream& output , Color  color) //does it need pass by refrence?
{
    switch (color)
    {

        case Color::Red :
            output << "Red";
        break;
    
        case Color::Yellow :
            output << "Yellow";
        break;
    
        case Color::Blue :
            output << "Blue";
        break;
        
        default:
            break;
    }
    return output;
}