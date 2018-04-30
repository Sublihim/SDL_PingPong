#include "Dbg.h"
#include <iostream>
#include <string>

std::ostream& operator << (std::ostream& stream, const SDL_Point& point)
{
    stream << "x = " << point.x << " y = " << point.y;
    return stream;
}

namespace Dbg
{

void PrintPoint(const SDL_Point& point, const std::string& msg)
{
    if (!msg.empty())
        std::cout << msg << " ";

    std::cout << point << std::endl;

}

}