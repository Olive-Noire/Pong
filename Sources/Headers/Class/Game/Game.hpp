#ifndef DEF_CLASS_GAME_HPP
#define DEF_CLASS_GAME_HPP

#include <SDL.h>
#include <vector>
#include <string>

#include "../Menu/Menu.hpp"
#include "./Element.hpp"

class Game {

    public:
    Game();

    ~Game();

    void Init(std::string WindowName,SDL_WindowFlags WindowMode,int resolutionX,int resolutionY,int x,int y);

    void Event();
    void Update();
    void Render();

    inline bool Run() const { return run; }

    void Clean();

    static bool keys[0x4000011A];
    static bool mouses[7];
    static int mousePos[3];
    static int wheel;

    static SDL_Renderer* renderer;
    static std::vector<Element*> ElementsInGame;

    //void InitElementsGame();
    //void CleanElementsGame();

    protected:
    bool run;

    bool pause;
    Menu* menu;

    int score1,score2;

    SDL_Window *windowGame;

};

#endif //DEF_CLASS_GAME_HPP