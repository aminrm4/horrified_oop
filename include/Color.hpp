#pragma once
#include <iostream>
namespace rgb
{
    enum class Color
    {
        Red,
        Blue,
        Yellow
    };

    std::ostream &operator<<(std::ostream &output, rgb::Color color);
}