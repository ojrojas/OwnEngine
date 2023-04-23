
#include <iostream>
#include <SDL2_mixer/SDL_mixer.h>
#include "../includes/soundmanager.hpp"

SoundManager::SoundManager()
{
    Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
}

bool SoundManager::Load(std::string fileName, std::string id, Sound_Type soundType)
{
    if(soundType == SOUND_MUSIC)
    {
        Mix_Music* music = Mix_LoadMUS(fileName.c_str());
    }
    return false;
}
void SoundManager::PlaySound(std::string id, int loop)
{
}
void SoundManager::PlayMusic(std::string id, int loop)
{
}


SoundManager::~SoundManager()
{
}
