#include "../../../Headers/Class/Game/Element.hpp"

#include "../../../Headers/Class/Game/Game.hpp"

Element::Element() {

    pos.SetAxeX(0);
    pos.SetAxeY(0);

    mouvement.SetLimit(0);
    mouvement.SetAxeX(0);
    mouvement.SetAxeY(0);

    texture = nullptr;
    rect.h = rect.w = rect.x = rect.y = 0;

}

Element::~Element() { SDL_DestroyTexture(texture); }

void Element::Update() {

    mouvement.Udapte();
    pos.Push(mouvement);

    rect.x = pos.GetAxeX();
    rect.y = pos.GetAxeY();

}

void Element::Render() {

    SDL_RenderCopy(Game::renderer,texture,&rect,&rect);

}

void Element::Mouv(int x,int y) {

    mouvement.Push((float)x,(float)y);

}

void Element::SetPos(int x,int y) {

    pos.SetAxeX((float)x);
    pos.SetAxeY((float)y);
    
}

void Element::SetMouv(bool m) { mouv = m; }
void Element::SetAxeMouvX(int mx) { mouvement.SetAxeX(mx); }
void Element::SetAxeMouvY(int my) { mouvement.SetAxeY(my); }