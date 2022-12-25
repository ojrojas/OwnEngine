#include <iostream>
#include "includes/texturemanager.hpp"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

typedef TextureManager TheTextureManager;
TextureManager* TextureManager::_instance = 0;
bool TextureManager::Load(std::string fileName, std::string id, SDL_Renderer* renderer, IMG_InitFlags initFlag)
{
    int flags = initFlag;
    int initStatus = IMG_Init(flags);
    if ((initStatus & flags) != flags)
    {
        std::cout << "SDL2_Image format not available" << std::endl;
    }


    SDL_Surface* tempSurface = IMG_Load(fileName.c_str());

    if(tempSurface == 0)
    {
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    if(texture != 0)
    {
        _textureMap[id] = texture;
        return true;
    }

    return false;
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(renderer,_textureMap[id],&srcRect, &destRect, 0, 0, flip); 

}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
     SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(renderer,_textureMap[id],&srcRect, &destRect, 0, 0, flip); 
}
