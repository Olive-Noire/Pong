#include "../../../Headers/Class/Menu/Image.hpp"

#include "../../../Headers/Class/Game/Game.hpp"

#include "../../../Headers/Functions/TexturesManagement.hpp"

Image::Image(std::string Path) {

    texture = LoadTexture(Path);
    rect.x = rect.y = rect.h = rect.w = 0;

}

Image::~Image() { SDL_DestroyTexture(texture); }

void Image::Update() {

    mouvement.Udapte();
    pos.Push(mouvement);

    rect.x = pos.GetAxeX();
    rect.y = pos.GetAxeY();

}

void Image::Render() {

    SDL_RenderCopy(Game::renderer,texture,NULL,&rect);

}

void Image::SetSize(int size) { rect.h = rect.w = size; }