#include "../../Headers/Functions/TexturesManagement.hpp"

#include <SDL_image.h>

#include "../../Headers/Class/Game/Game.hpp"

void ImageInit() { if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP) == 0) {} else {} }

SDL_Texture* LoadTexture(std::string Path) {

    SDL_Surface* surface = nullptr;
    std::string TexturesDirectory = SDL_GetBasePath();
    TexturesDirectory.append("/Data/Textures/");
    SDL_RWops* File = SDL_RWFromFile((TexturesDirectory + Path).c_str(),"rb");

    if (!File) File = SDL_RWFromFile((TexturesDirectory + "not_found.png").c_str(),"rb");

    if (IMG_isXV(File)) surface = IMG_LoadXV_RW(File);
    if (IMG_isPNG(File)) surface = IMG_LoadPNG_RW(File);
    if (IMG_isJPG(File)) surface = IMG_LoadJPG_RW(File);
    if (IMG_isBMP(File)) surface = IMG_LoadBMP_RW(File);
    if (IMG_isGIF(File)) surface = IMG_LoadGIF_RW(File);
    if (IMG_isTIF(File)) surface = IMG_LoadTIF_RW(File);
    if (IMG_isICO(File)) surface = IMG_LoadICO_RW(File);
    if (IMG_isSVG(File)) surface = IMG_LoadSVG_RW(File);
    if (IMG_isCUR(File)) surface = IMG_LoadCUR_RW(File);
    if (IMG_isLBM(File)) surface = IMG_LoadLBM_RW(File);
    if (IMG_isPCX(File)) surface = IMG_LoadPCX_RW(File);
    if (IMG_isPNM(File)) surface = IMG_LoadPNM_RW(File);
    if (IMG_isXCF(File)) surface = IMG_LoadXCF_RW(File);
    if (IMG_isXPM(File)) surface = IMG_LoadXPM_RW(File);
    if (IMG_isWEBP(File)) surface = IMG_LoadWEBP_RW(File);

    return SDL_CreateTextureFromSurface(Game::renderer,surface);

}

void ImageDestroy() { IMG_Quit(); }