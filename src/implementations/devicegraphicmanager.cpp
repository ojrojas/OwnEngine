#include <iostream>
#include <SDL.h>
#include "../includes/devicegraphicmanager.hpp"

DeviceGraphicManager::DeviceGraphicManager()
{
}

DeviceGraphicManager::~DeviceGraphicManager()
{
}

void DeviceGraphicManager::SetRenderer(SDL_Renderer *renderer)
{
    _renderer = renderer;
}

void DeviceGraphicManager::CleanRenderer(SDL_Renderer *renderer)
{
    _renderer = renderer = nullptr;
}

void DeviceGraphicManager::ApplyChanges()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    Initialize();
}

void DeviceGraphicManager::Initialize()
{
    try
    {
        /* code */
        SDL_Init(SDL_INIT_EVERYTHING);
        std::cout << "SDL_Init successfull " << std::endl;
        _window = SDL_CreateWindow(_title, _positionX, _positionY, _width, _height, _windowFlags);
        _renderer = SDL_CreateRenderer(_window, 0, _rendererFlags);
        SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 50);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error creating window or renderer" << e.what() << '\n';
    }
}