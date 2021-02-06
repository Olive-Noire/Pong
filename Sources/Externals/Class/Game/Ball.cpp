#include "../../../Headers/Class/Game/Ball.hpp"

#include <ctime>

#include "../../../Headers/Class/Game/Game.hpp"

#include "../../../Headers/Functions/SoundsManagement.hpp"

Ball::Ball() {

    mouvement.SetLimit(10);
    mouvement.Push(5,0);
    rect.h = rect.w = 10;

    pos.SetAxeX(245);
    pos.SetAxeY(245);

}

Ball::~Ball() { SDL_DestroyTexture(texture); }

void Ball::Update() {

    if (mouv) pos.Push(mouvement); else if (Game::keys[SDLK_SPACE]) mouv = true;

    rect.x = pos.GetAxeX();
    rect.y = pos.GetAxeY();

    int x,y;
    SDL_GetRendererOutputSize(Game::renderer,&x,&y);

    if (rect.x < 0) { mouvement.SetAxeX(-mouvement.GetAxeX()); PlaySound("beep.wav"); }
    if (rect.y < 0) { mouvement.SetAxeY(-mouvement.GetAxeY()); PlaySound("beep.wav"); }
    if (rect.x > x) { mouvement.SetAxeX(-mouvement.GetAxeX()); PlaySound("beep.wav"); }
    if (rect.y > y) { mouvement.SetAxeY(-mouvement.GetAxeY()); PlaySound("beep.wav"); }

    for (int i = 0;i < Game::ElementsInGame.size();i++) {

        if (Game::ElementsInGame[i] != this) {

            if ((rect.x + rect.w) >= Game::ElementsInGame[i]->GetPosX() && (Game::ElementsInGame[i]->GetPosX() + Game::ElementsInGame[i]->rect.w) >= rect.x && (rect.y + rect.h) >= Game::ElementsInGame[i]->GetPosY() && (Game::ElementsInGame[i]->GetPosY() + Game::ElementsInGame[i]->rect.h) >= rect.y) {
                
                mouvement.SetAxeX(-mouvement.GetAxeX());
                srand(time(0));

                if (rand() % 2) mouvement.SetAxeY((mouvement.GetAxeY() + (rand() % 5))); else mouvement.SetAxeY((mouvement.GetAxeY() - (rand() % 5)));
                PlaySound("beep.wav");
                
            }

        }

    }

}

void Ball::Render() {

    SDL_SetRenderDrawColor(Game::renderer,255,140,0,255);
    SDL_RenderFillRect(Game::renderer,&rect);
    SDL_SetRenderDrawColor(Game::renderer,0,0,0,255);

}