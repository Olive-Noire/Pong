#include "../../../Headers/Class/Game/Player.hpp"

#include "../../../Headers/Class/Game/Ball.hpp"
#include "../../../Headers/Class/Game/Game.hpp"

Player::Player(bool m,bool c) {

    rect.w = 10;
    rect.h = 200;
    if ((mainP = m)) { pos.SetAxeX(5); pos.SetAxeY(1); } else { pos.SetAxeX(485); pos.SetAxeY(300); }
    mouvement.SetLimit(5);

    cpu = c;

}

Player::~Player() { SDL_DestroyTexture(texture); }

void Player::Update() {

    mouvement.Udapte();
    pos.Push(mouvement);

    rect.x = pos.GetAxeX();
    rect.y = pos.GetAxeY();

    if (!cpu) {

        mouvement.SetLimit(5);

        if (mainP) {

            if (Game::keys[SDLK_UP] && rect.x > 0) mouvement.Push(0,-5);
            if (Game::keys[SDLK_DOWN] && rect.x < 500) mouvement.Push(0,5);

        } else {
        
            if (Game::mouses[SDL_BUTTON_LEFT] && Game::mousePos[1] > 0 && Game::mousePos[1] < 500) pos.SetAxeY((pos.GetAxeY() + Game::mousePos[3]));

            if (Game::keys[SDLK_z] || Game::keys[SDLK_w]) mouvement.Push(0,-5);
            if (Game::keys[SDLK_s]) mouvement.Push(0,5);

        }

    } else {

        mouvement.SetLimit(999);
                
        if ((rect.y + (rect.h / 2)) > Game::ElementsInGame[0]->GetPosY()) mouvement.Push(0,-rand() % 4);
        if ((rect.y + (rect.h / 2)) < Game::ElementsInGame[0]->GetPosY()) mouvement.Push(0,rand() % 4);

    }

}

void Player::Render() {

    if (mainP) SDL_SetRenderDrawColor(Game::renderer,255,0,0,255); else SDL_SetRenderDrawColor(Game::renderer,0,0,255,255);
    SDL_RenderFillRect(Game::renderer,&rect);
    SDL_SetRenderDrawColor(Game::renderer,0,0,0,255);

}

void Player::SetUser(bool u) { cpu = u; }