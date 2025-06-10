#pragma
#include <iostream>

enum class Color
{
    Red , Blue , Yellow
};

std::ostream& operator<<(std::ostream& output , Color color);