#ifndef __SOUNDMANAGER_H__
#define __SOUNDMANAGER_H__

#include <iostream>
#include <map>
#include <SDL2_mixer/SDL_mixer.h>
#include "enums/enumsound.hpp"

using namespace std;

class SoundManager
{
public:
    
    static SoundManager *Instance();
    bool Load(std::string fileName, std::string id, Sound_Type soundType);
    void PlaySound(std::string id, int loop);
    void PlayMusic(std::string id, int loop);

private:
    static SoundManager *_instance;
    std::map<std::string, Mix_Chunk *> _sfxs;
    std::map<std::string, Mix_Music *> _music;

    SoundManager();
    ~SoundManager();

    SoundManager(const SoundManager&);
    SoundManager &operator= (const SoundManager&);
};

typedef SoundManager TheSoundManager;

#endif