#ifndef DBG_H_INCLUDED
#define DBG_H_INCLUDED

#include <ostream>
#include "Ball.h"
#include <SDL2/SDL.h>

std::ostream& operator << (std::ostream& stream, const SDL_Point& point);

class Ball;
class SDL_Point;

namespace Dbg {

void PrintPoint(const SDL_Point& point, const std::string& msg = "");
void PrintDoublePoint (const SDL_Point& firstPoint, const SDL_Point& secondPoint, const std::string& msg = "");
void PrintTriplePoint (const SDL_Point& firstPoint, const SDL_Point& secondPoint, const SDL_Point& endPoint, const std::string& msg = "");
void PrintAbs(const SDL_Point& firstPoint, const SDL_Point& secondPoint, const Ball& ball);

}

#endif //DBG_H_INCLUDED