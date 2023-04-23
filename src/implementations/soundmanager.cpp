#include <iostream>
#include <SDL_mixer.h>
#include "../includes/soundmanager.hpp"

SoundManager *SoundManager::_instance = nullptr;

SoundManager::SoundManager()
{
    Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
}

bool SoundManager::Load(std::string fileName, std::string id, Sound_Type soundType, MIX_InitFlags flagsMix)
{
    if (soundType == SOUND_MUSIC)
    {
        int initMix = Mix_Init(flagsMix);
        if((initMix & flagsMix) != flagsMix)
        {
             std::cout << "Could not load mixer: Error - " << Mix_GetError();
            return false;
        }

        Mix_Music *music = Mix_LoadMUS(fileName.c_str());
        if (music == nullptr)
        {
            std::cout << "Could not load music: Error - " << Mix_GetError();
            return false;
        }
        _musicMap[id] = music;
        return true;
    }
    else if (soundType == SOUND_SFX)
    {
        Mix_Chunk *chunk = Mix_LoadWAV(fileName.c_str());
        if (chunk == nullptr)
        {
            std::cout << "Could not load sfx: Error - " << Mix_GetError();
            return false;
        }
        _sfxsMap[id] = chunk;
        return true;
    }
    return false;
}
void SoundManager::PlaySound(std::string id, int loop)
{
    Mix_PlayChannel(-1, _sfxsMap[id], loop);
}
void SoundManager::PlayMusic(std::string id, int loop)
{
    Mix_PlayMusic(_musicMap[id], loop);
}

SoundManager::~SoundManager()
{
    Mix_CloseAudio();
}
