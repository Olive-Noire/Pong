#include "../../Headers/Functions/TextsManagement.hpp"

#include <SDL.h>
#include <SDL_ttf.h>

#include "../../Headers/Class/Game/Game.hpp"

#include "../../Headers/Functions/TexturesManagement.hpp"

void TextInit() {

    if (TTF_Init() == 0) {} else exit(1);

}

SDL_Texture* LoadText(std::string content,TTF_Font* font,SDL_Color color) {

    SDL_Surface* surface = TTF_RenderText_Solid(font,content.c_str(),color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer,surface);
    SDL_FreeSurface(surface);
    return texture;

}

void TextDestroy() {

    TTF_CloseFont(NULL);
    TTF_Quit();

}