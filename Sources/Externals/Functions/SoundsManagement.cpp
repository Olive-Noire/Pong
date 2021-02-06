#include "../../Headers/Functions/SoundsManagement.hpp"

#include <SDL.h>
#include <SDL_mixer.h>
#include <vector>
#include <string>

Mix_Music* music = nullptr;
std::vector<Mix_Chunk*> sounds;

void SoundInit() { 

    if (SDL_Init(SDL_INIT_AUDIO) == 0) {} else {}

    if (MIX_INIT_MP3 == Mix_Init(MIX_INIT_MP3)) {} else {}

    Mix_OpenAudio(44100, AUDIO_S16SYS, 0, 640);

    Mix_AllocateChannels(5);
    for (int i = 0;i < 5;i++) sounds.push_back(new Mix_Chunk);
    
}

void PlayMusic(std::string Path,bool repeat = false) {

    std::string SoundsDirectory = SDL_GetBasePath();
    SoundsDirectory.append("Data\\Sounds\\");
    music = Mix_LoadMUS((SoundsDirectory + Path).c_str());

    Mix_PlayMusic(music,repeat);

}

void PlaySound(std::string Path) {

    std::string SoundsDirectory = SDL_GetBasePath();
    SoundsDirectory.append("Data\\Sounds\\");

    for (int i = 0;i < sounds.size();i++) {

        if (Mix_Playing(i) == 0) {
            
            Mix_FreeChunk(sounds[i]);
            sounds[i] = Mix_LoadWAV((SoundsDirectory + Path).c_str());
            Mix_PlayChannel(i, sounds[i], false);
            i = sounds.size();

        } /*else if (i == (sounds.size() - 1)) {

            Mix_AllocateChannels(1);
            sounds.push_back(new Mix_Chunk);

        }*/

    }

}

void SetVolume(int volume) {

    Mix_VolumeMusic(volume);
    for (int i = 0;i < sounds.size();i++) Mix_Volume(i,volume);

}

void SoundDestroy() {

    for (int i = 0;i < sounds.size();i++) { Mix_FreeChunk(sounds[i]); delete sounds[i]; }
    Mix_FreeMusic(music);
    Mix_Quit();

}