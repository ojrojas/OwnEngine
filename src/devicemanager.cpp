#include <iostream>
#include <SDL2/SDL.h>
#include "includes/devicemanager.hpp"
#include "includes/game.hpp"

DeviceManager::DeviceManager()
{
    Initialize();
}

DeviceManager::~DeviceManager()
{
}

void DeviceManager::SetRenderer(SDL_Renderer *renderer)
{
    _renderer = renderer;
}

void DeviceManager::CleanRenderer(SDL_Renderer *renderer)
{
    _renderer = renderer = nullptr;
}

void DeviceManager::ApplyChanges()
{   
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    Initialize();
}

void DeviceManager::Initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL_Init successfull " << std::endl;
        _window = SDL_CreateWindow(_title, _positionX, _positionY, _width, _height, _windowFlags);

        if (_window)
        {
            _renderer = SDL_CreateRenderer(_window, 0, _rendererFlags);

            if (_renderer)
            {
                SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 50);
            }
            else
            {
                std::cout << "Renderer could not be created: " << SDL_GetError() << std::endl;
            }
        }
        else
        {
            std::cout << "Window could not be created: " << SDL_GetError() << std::endl;
        }
    }
    else
    {
        std::cout << "SDL could not be initialized: " << SDL_GetError() << std::endl;
    }
}


