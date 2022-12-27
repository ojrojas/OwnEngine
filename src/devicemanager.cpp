#include <iostream>
#include <SDL2/SDL.h>
#include "includes/devicemanager.hpp"
#include "includes/game.hpp"

void DeviceManager::SetRenderer(SDL_Renderer *renderer)
{
    _renderer = renderer;
}

void DeviceManager::CleanRenderer(SDL_Renderer *renderer)
{
    _renderer = renderer = nullptr;
}