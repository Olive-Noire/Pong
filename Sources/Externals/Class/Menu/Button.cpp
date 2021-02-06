#include "../../../Headers/Class/Menu/Button.hpp"

#include "../../../Headers/Class/Game/Game.hpp"

Button::Button(std::string t,int s,Uint8 c[3]) {

    color[0] = c[0];
    color[1] = c[1];
    color[2] = c[2];

    text = new Text(t,((size = s) / 2),color);

    rect.h = size;
    rect.w = ((size * t.size()) - size);
    
}

Button::~Button() { SDL_DestroyTexture(texture); delete text; }

void Button::Update() {

    mouvement.Udapte();
    pos.Push(mouvement);

    rect.x = pos.GetAxeX();
    rect.y = pos.GetAxeY();

    text->Update();
    text->SetPos((pos.GetAxeX() + (size / 4)),(pos.GetAxeY() + (size / 4)));

}

void Button::Render() {

    SDL_SetRenderDrawColor(Game::renderer,color[0],color[1],color[2],255);
    SDL_RenderDrawRect(Game::renderer,&rect);
    SDL_SetRenderDrawColor(Game::renderer,0,0,0,255);

    text->Render();

}