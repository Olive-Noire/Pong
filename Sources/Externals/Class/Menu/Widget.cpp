#include "../../../Headers/Class/Menu/Widget.hpp"

#include "../../../Headers/Class/Game/Game.hpp"

bool Widget::Click() {

    if ((rect.x + rect.w) >= Game::mousePos[0] && (Game::mousePos[0] + 1) >= rect.x && (rect.y + rect.h) >= Game::mousePos[1] && (Game::mousePos[1] + 1) >= rect.y && Game::mouses[SDL_BUTTON_LEFT]) return true; else return false;

}

Widget::~Widget() { SDL_DestroyTexture(texture); }

void Widget::Render() {}
void Widget::Update() {}