#ifndef __DEVICEMANAGER_H__
#define __DEVICEMANAGER_H__

#include <iostream>
#include <SDL2/SDL.h>
#include "game.hpp"

class DeviceManager
{
public:
    DeviceManager();
    ~DeviceManager();
    void SetRenderer(SDL_Renderer* renderer);
    void CleanRenderer(SDL_Renderer* renderer);
    SDL_Renderer* _renderer = nullptr;
    SDL_Window *_window = nullptr;
    void ApplyChanges();
    unsigned int _width = 640, _height = 480, _positionX = 20, _positionY = 20;
    const char *_title = "MainWindowDefault";

private:
    SDL_WindowFlags _windowFlags = SDL_WINDOW_SHOWN;
    SDL_RendererFlags _rendererFlags = SDL_RENDERER_ACCELERATED;
    void Initialize();
};

#endif