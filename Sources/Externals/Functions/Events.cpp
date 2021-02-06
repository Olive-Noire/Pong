#include "../../Headers/Functions/Events.hpp"

#include <SDL.h>

#include "../../Headers/Class/Game/Game.hpp"

void UpdateKeys(SDL_Event event) {

    switch (event.type) {

		case SDL_KEYDOWN:
		Game::keys[event.key.keysym.sym] = true;
		break;

		case SDL_KEYUP:
		Game::keys[event.key.keysym.sym] = false;
		break;

		default:
		break;

	}

}

void UpdateMouse(SDL_Event event) {

    switch(event.type) {

        case SDL_MOUSEBUTTONDOWN:
        Game::mouses[event.button.button] = true;
        break;

        case SDL_MOUSEBUTTONUP:
        Game::mouses[event.button.button] = false;
        break;

        case SDL_MOUSEMOTION:
        Game::mousePos[0] = event.motion.x;
        Game::mousePos[1] = event.motion.y;
        Game::mousePos[2] = event.motion.xrel;
        Game::mousePos[3] = event.motion.yrel;
        break;

        case SDL_MOUSEWHEEL:
        Game::wheel = event.wheel.y;
        break;

        default:
        //Game::mousePos[2] = 0;
        //Game::mousePos[3] = 0;
        //Game::wheel = 0;
        break;

    }

    if (event.type != SDL_MOUSEMOTION) {

        Game::mousePos[2] = 0;
        Game::mousePos[3] = 0;

    }

    if (event.type != SDL_MOUSEWHEEL) Game::wheel = 0;

}