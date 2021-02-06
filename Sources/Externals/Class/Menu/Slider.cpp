#include "../../../Headers/Class/Menu/Slider.hpp"

#include "../../../Headers/Class/Game/Game.hpp"

Slider::Slider() {

    value = 0;

    cursor.x = cursor.y = rect.x = rect.y = 0;
    cursor.h = cursor.w = 30;
    rect.h = 10;
    rect.w = 150;

}

Slider::~Slider() { SDL_DestroyTexture(texture); }

void Slider::Update() {

    mouvement.Udapte();
    pos.Push(mouvement);

    rect.x = pos.GetAxeX();
    rect.y = pos.GetAxeY();
    cursor.x = (rect.x + value);

    if ((cursor.y + cursor.h) >= Game::mousePos[1] && (Game::mousePos[1] + 1) >= cursor.y && Game::mouses[SDL_BUTTON_LEFT]) {

        cursor.x = (Game::mousePos[0] - (cursor.w / 2));

        if (cursor.x < rect.x) cursor.x = rect.x;
        if ((cursor.x + cursor.w) > (rect.x + rect.w)) cursor.x = ((rect.x + rect.w) - cursor.w);
    }

    cursor.y = rect.y - ((cursor.h - rect.h) / 2);
    value = (cursor.x - rect.x);

}

void Slider::Render() {

    SDL_SetRenderDrawColor(Game::renderer,255,255,255,255);
    SDL_RenderFillRect(Game::renderer,&rect);
    SDL_SetRenderDrawColor(Game::renderer,0,0,255,255);
    SDL_RenderFillRect(Game::renderer,&cursor);
    SDL_SetRenderDrawColor(Game::renderer,0,0,0,255);

}

void Slider::SetValue(int v) { value = v; }