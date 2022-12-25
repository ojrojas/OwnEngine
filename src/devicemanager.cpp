#include <iostream>
#include "includes/devicemanager.hpp"
#include "includes/devicemanager.hpp"

DeviceManager::DeviceManager()
{
    if (!DeviceManager::CreateWindow(SDL_RENDERER_ACCELERATED))
    {
        std::cout << "Error SDL dot not initialized";
    }
}

bool DeviceManager::CreateWindow(SDL_RendererFlags flag)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Success init sdl\n";
        _window = SDL_CreateWindow("mainwindow", _positionX, _positionY, _width, _height, flag);
        return true;
    }

    return false;
}

DeviceManager::~DeviceManager()
{
}

int DeviceManager::GetWidthDevice()
{
    return _width;
}

void DeviceManager::SetWidthDevice(int width)
{
    _width = width;
}

int DeviceManager::GetHeightDevice()
{
    return _height;
}

void DeviceManager::SetHeightDevice(int height)
{
    _height = height;
}

void DeviceManager::SetPositionX(int positionX)
{
    _positionX = positionX;
}

int DeviceManager::GetPositionX()
{
    return _positionX;
}

void DeviceManager::SetPositionY(int positionY)
{
    _positionY = positionY;
}

int DeviceManager::GetPositionY()
{
    return _positionY;
}

SDL_Renderer *DeviceManager::GetRenderer(SDL_RendererFlags flag)
{
    if (_window != 0)
    {
        std::cout << "Create windows success\n";
        _renderer = SDL_CreateRenderer(_window, -1, flag);
        if (_renderer != 0)
        {
            SDL_SetRenderDrawColor(_renderer, 255, 230, 149, 0);
            SDL_RenderClear(_renderer);
        }
        else
        {
            std::cout << "Renderer fail init\n";
            return nullptr;
        }
    }
    else
    {
        std::cout << "Window fail to create\n";
        return nullptr;
    }

    return _renderer;
}

SDL_Window *DeviceManager::GetWindow()
{
    return _window;
}

void DeviceManager::CleanDevice()
{
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
}
