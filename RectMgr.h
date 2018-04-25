#ifndef RECTMGR_H_INCLUDED
#define RECTMGR_H_INCLUDED

#include "MainConstants.h"
#include "Rect.h"
class RectMgr
{
private:
    Rect *rect, *rect_cleaner;
public:
    RectMgr();
    void setBeginXY(int x, int y);
    void setWidth(int w);
    void setHeight(int h);
    void draw(SDL_Renderer *renderer, bool clean = false);
};


#endif // RECTMGR_H_INCLUDED