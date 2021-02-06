#ifndef DEF_SOUNDS_MANAGEMENT_HPP
#define DEF_SOUNDS_MANAGEMENT_HPP

#include <string>

void SoundInit();
void PlayMusic(std::string Path,bool repeat);
void PlaySound(std::string Path);
void SetVolume(int volume);
void SoundDestroy();

#endif //DEF_SOUNDS_MANAGEMENT_HPP