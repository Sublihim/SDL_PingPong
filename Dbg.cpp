#include "Dbg.h"

#include <iostream>
#include <string>
#include <math.h>

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

void PrintDoublePoint (const SDL_Point& firstPoint, const SDL_Point& secondPoint, const std::string& msg)
{
    if (!msg.empty())
        std::cout << msg << " ";

    std::cout << "f_p: " << firstPoint << " s_p: " << secondPoint << std::endl;
}

void PrintTriplePoint (const SDL_Point& firstPoint, const SDL_Point& secondPoint, const SDL_Point& endPoint, const std::string& msg)
{
    if (!msg.empty())
        std::cout << msg << " ";

    std::cout << "f_p: " << firstPoint << " s_p: " << secondPoint << " e_p" << endPoint << std::endl;
}


void PrintAbs(const SDL_Point& firstPoint, const SDL_Point& secondPoint, const Ball& ball)
{
    std::cout << abs(secondPoint.y - firstPoint.y) << " <= " << (const_cast<Ball&>(ball)).getRadius() << std::endl;
}

}