#ifndef DEF_CLASS_GAME_ELEMENT_HPP
#define DEF_CLASS_GAME_ELEMENT_HPP

#include <SDL.h>

#include "../Physic/Velocity.hpp"

class Element {

    public:
    Element();
    ~Element();

    virtual void Update();
    virtual void Render();

    void Mouv(int x,int y);
    void SetPos(int x,int y);

    int inline GetPosX() const { return pos.GetAxeX(); }
    int inline GetPosY() const { return pos.GetAxeY(); }

    void SetMouv(bool m);

    void SetAxeMouvY(int my);
    void SetAxeMouvX(int mx);

    SDL_Rect rect;

    protected:
    Vector pos;
    Velocity mouvement;

    SDL_Texture* texture;
    bool mouv = false;

};

#endif //DEF_CLASS_GAME_ELEMENT_HPP