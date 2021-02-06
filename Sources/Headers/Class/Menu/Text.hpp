#ifndef DEF_CLASS_MENU_TEXT_HPP
#define DEF_CLASS_MENU_TEXT_HPP

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

#include "../Menu/Widget.hpp"

class Text : public Widget {

    public:
    Text(std::string t,int s,Uint8 color[3]);
    ~Text();

    void AddContour(int s,Uint8 color[3]);

    void Update();
    void Render();

    void SetText(std::string text);

    protected:
    SDL_Rect rectContour;
    SDL_Texture* contour;
    std::string text;
    SDL_Color textColor;
    TTF_Font* font;

    int size;

};

#endif //DEF_CLASS_MENU_TEXT_HPP