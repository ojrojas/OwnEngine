#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "includes/texturemanager.hpp"

typedef TextureManager TheTextureManager;
TextureManager *TextureManager::_instance = 0;
bool TextureManager::Load(std::string fileName, std::string id, SDL_Renderer *renderer, IMG_InitFlags initFlag)
{
    int flags = initFlag;
    int initStatus = IMG_Init(flags);
    if ((initStatus & flags) != flags)
    {
        std::cout << "SDL2_Image format not available" << std::endl;
    }

    const char *fileString = fileName.c_str();
    SDL_Surface *tempSurface = IMG_Load(fileString);

    if (tempSurface == 0)
    {
        return false;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    if (texture != 0)
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

    SDL_RenderCopyEx(renderer, _textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::DrawFrame(std::string id, SDL_Renderer *renderer, SDL_Rect srcRect, SDL_Rect dstRect, double angle, SDL_Point pointAngle, SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(renderer, _textureMap[id], &srcRect, &dstRect, 0, 0, flip);
}
void TextureManager::BeginRender(SDL_Renderer *renderer)
{
    SDL_RenderClear(renderer);
}

void TextureManager::FinishRender(SDL_Renderer *renderer)
{
    SDL_RenderPresent(renderer);
}
