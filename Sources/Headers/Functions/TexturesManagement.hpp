#ifndef DEF_TEXTURES_MANAGEMENT_HPP
#define DEF_TEXTURES_MANAGEMENT_HPP

#include <SDL.h>
#include <string>

void ImageInit();
SDL_Texture* LoadTexture(std::string Path);
void ImageDestroy();

#endif //DEF_TEXTURES_MANAGEMENT_HPP