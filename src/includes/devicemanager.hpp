#ifndef __DEVICEMANAGER_H__
#define __DEVICEMANAGER_H__

#include <iostream>
#include <SDL2/SDL.h>

class DeviceManager
{
    int _width;
    int _height;
    int _positionX;
    int _positionY;
    SDL_Renderer* _renderer;
    SDL_Window* _window;

    public:
    DeviceManager();
    ~DeviceManager();

    bool CreateWindow(SDL_RendererFlags flag);
    int GetWidthDevice();
    void SetWidthDevice(int width);

    int GetHeightDevice();
    void SetHeightDevice(int height);

    void SetPositionX(int positionX);
    int GetPositionX();

    void SetPositionY(int positionY);
    int GetPositionY();

    SDL_Renderer* GetRenderer(SDL_RendererFlags flag);
    SDL_Window* GetWindow();

    void CleanDevice();
};




#endif