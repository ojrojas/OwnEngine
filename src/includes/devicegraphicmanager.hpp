#ifndef __DEVICEMANAGER_H__
#define __DEVICEMANAGER_H__

#include <iostream>
#include <SDL.h>

class DeviceGraphicManager
{
public:
    DeviceGraphicManager();
    ~DeviceGraphicManager();
    void SetRenderer(SDL_Renderer* renderer);
    void CleanRenderer(SDL_Renderer* renderer);
    SDL_Renderer* _renderer = nullptr;
    SDL_Window *_window = nullptr;
    void ApplyChanges();
    unsigned int _width = 640, _height = 480, _positionX = 20, _positionY = 20;
    const char *_title = "MainWindowDefault";
    Uint32 _windowFlags;
    SDL_RendererFlags _rendererFlags;

private:
    void Initialize();
};

#endif