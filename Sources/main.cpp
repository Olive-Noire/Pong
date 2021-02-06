#include "./Headers/Class/Game/Game.hpp"

#include <SDL.h>

int main(int argc,char* argv[]) {

    const int frameDelay = 1000 / 120;

    Uint32 frameStart;
    int frameTime;

    Game game;

    while (game.Run()) {

        frameStart = SDL_GetTicks();

        game.Event();
        game.Update();
        game.Render();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);

    }

    return 0;

}

// Command x32 : g++ -m32 ./Sources/*.cpp ./Sources/Headers/Class/Game/*hpp ./Sources/Externals/Class/Game/*cpp ./Sources/Headers/Class/Physic/*hpp ./Sources/Externals/Class/Physic/*cpp ./Sources/Headers/Class/Menu/*hpp ./Sources/Externals/Class/Menu/*cpp ./Sources/Headers/Functions/*hpp ./Sources/Externals/Functions/*cpp -o "./bin/x32/Pong" -I include -L lib/SDL/ -Insignw32 -lSDL_Image/SDL2_image -lSDL_ttf/SDL2_ttf -lSDL_Mixer/SDL2_mixer -lSDL_Basic/SDL2main -lSDL_Basic/SDL2 -s -std=c++17 -mwindows
// Command x64 : g++ -m64 ./Sources/*.cpp ./Sources/Headers/Class/*hpp ./Sources/Externals/Class/*cpp ./Sources/Headers/Fonctions/*hpp ./Sources/Externals/Fonctions/*cpp -o "./bin/x64/Hero Dungeon" -I include -L lib/SDL/SDL_Basic/ -Insignw64 -lSDL2main -lSDL2 -s -std=c++17 -mwindows