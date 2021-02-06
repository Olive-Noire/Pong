#ifndef DEF_CLASS_GAME_BALL_HPP
#define DEF_CLASS_GAME_BALL_HPP

#include "./Element.hpp"

class Ball : public Element {

    public:
    Ball();
    ~Ball();

    void Update();
    void Render();

    protected:

};

#endif //DEF_CLASS_GAME_BALL_HPP