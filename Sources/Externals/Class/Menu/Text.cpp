#include "../../../Headers/Class/Menu/Text.hpp"

#include <SDL.h>
#include <SDL_ttf.h>

#include "../../../Headers/Class/Game/Game.hpp"

#include "../../../Headers/Functions/TextsManagement.hpp"

Text::Text(std::string t,int s,Uint8 color[3]) : Widget() {

    std::string FontPath = SDL_GetBasePath();
    FontPath.append(".\\Data\\Fonts\\pixel.ttf");

    contour = nullptr;
    text = t;

    textColor = {color[0],color[1],color[2]};
    texture = LoadText((text = t),(font = TTF_OpenFont(FontPath.c_str(),(size = s))),textColor);

    rect.x = rect.y = 0;
    rect.h = size;
    rect.w = (size * text.size());

}

Text::~Text() { SDL_DestroyTexture(texture); TTF_CloseFont(font); }

void Text::AddContour(int s,Uint8 color[3]) {

    std::string FontPath = SDL_GetBasePath();
    FontPath.append(".\\Data\\Fonts\\pixel.ttf");

    SDL_Color contourColor = {color[0],color[1],color[2]};

    contour = LoadText(text,TTF_OpenFont(FontPath.c_str(),size),contourColor);
    rectContour.x = (rect.x - s);
    rectContour.y = (rect.y - s);
    rectContour.h = (rect.h + (s * 2));
    rectContour.w = (rect.w + (s * 2));

}

void Text::Update() {

    mouvement.Udapte();
    pos.Push(mouvement);

    rect.x = pos.GetAxeX();
    rect.y = pos.GetAxeY();

    rectContour.x = rect.x - 5;
    rectContour.y = rect.y - 5;

}

void Text::Render() {

    SDL_RenderCopy(Game::renderer,contour,NULL,&rectContour);
    SDL_RenderCopy(Game::renderer,texture,NULL,&rect);

}

void Text::SetText(std::string t) {

    if (t != text) {

        std::string FontPath = SDL_GetBasePath();
        FontPath.append(".\\Data\\Fonts\\pixel.ttf");

        SDL_DestroyTexture(texture);
        texture = LoadText((text = t),font,textColor);
        rect.w = (size * text.size());

    }

}