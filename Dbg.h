#ifndef DBG_H_INCLUDED
#define DBG_H_INCLUDED

#include <SDL2/SDL.h>
#include <ostream>

std::ostream& operator << (std::ostream& stream, const SDL_Point& point);

namespace Dbg {

void PrintPoint(const SDL_Point& point, const std::string& msg = "");

}

#endif //DBG_H_INCLUDED