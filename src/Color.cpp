#include "Color.hpp"

std::ostream& operator<<(std::ostream& output , Color & color)
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