#ifndef FONTMGR_H_INCLUDED
#define FONTMGR_H_INCLUDED

#include <iostream>
#include <string>
#include <SDL2/SDL_ttf.h>
#include "MainConstants.h"

typedef enum {
    right,
    left
} fontAlign;

class FontMgr
{
private:
    TTF_Font *font;
    SDL_Surface *surface;
    SDL_Texture *texture;
    std::string font_name;
    int font_size;
    SDL_Color font_color;

    int letter_size_px;
    int scn_indent;
public:
    FontMgr();
    ~FontMgr();
    void setLetterSizeInPX(size_t l_size_px);
    void setFontName(std::string f_name);
    void setFontSize(int f_size);
    void setFontColor(const SDL_Color &f_color);
    void paintText(SDL_Renderer *renderer, std::string text, int y, int h, fontAlign f_align = fontAlign::right);
    void reloadFont();
};


#endif // FONTMGR_H_INCLUDED