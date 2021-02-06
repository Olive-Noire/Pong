#ifndef DEF_CLASS_GAME_PLAYER_HPP
#define DEF_CLASS_GAME_PLAYER_HPP

#include "./Element.hpp"

class Player : public Element {

    public:
    Player(bool m,bool c);
    ~Player();

    void Update();
    void Render();

    void SetUser(bool u);
    inline bool IsBot() const { return cpu; }

    protected:
    bool mainP;
    bool cpu;

};

#endif //DEF_CLASS_GAME_PLAYER_HPP