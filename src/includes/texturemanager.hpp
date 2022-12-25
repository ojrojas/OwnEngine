#ifndef __TextureManager_H__
#define __TextureManager_H__

#include <iostream>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>


class TextureManager
{
public:
     ~TextureManager();
    static TextureManager* Instance()
    {
        if (_instance == nullptr)
        {
            _instance = new TextureManager();
            return _instance;
        }

        return _instance;
    }
    
    bool Load(std::string fileName, std::string id, SDL_Renderer *renderer, IMG_InitFlags initFlag);
    void Draw(std::string id, int x, int y, int width, int height, SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    std::map<std::string, SDL_Texture *> _textureMap;

    typedef TextureManager* TheTextureManager;

private:
    static TextureManager *_instance;
};

#endif