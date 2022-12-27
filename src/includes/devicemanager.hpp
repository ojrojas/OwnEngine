#ifndef __DEVICEMANAGER_H__
#define __DEVICEMANAGER_H__

#include <iostream>
#include <SDL2/SDL.h>
#include "game.hpp"

class DeviceManager
{
public:
    void SetRenderer(SDL_Renderer* renderer);
    void CleanRenderer(SDL_Renderer* renderer);
    SDL_Renderer* _renderer = nullptr;
    SDL_Window *_window = nullptr;

private:
    unsigned int _width = 640, _heigth = 480, _positionX = 20, _positionY = 20;
    const char *_title = "MainWindowDefault";
    SDL_WindowFlags _windowFlags = SDL_WINDOW_SHOWN;
};

#endif