#ifndef DEF_TEXT_MANAGEMENT_HPP
#define DEF_TEXT_MANAGEMENT_HPP

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

void TextInit();
SDL_Texture* LoadText(std::string content,TTF_Font* font,SDL_Color color);
void TextDestroy();

#endif //DEF_TEXT_MANAGEMENT_HPP