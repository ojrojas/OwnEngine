#ifndef __Game_H__
#define __Game_H__
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "gametime.hpp"
#include "devicegraphicmanager.hpp"
#include "timespan.hpp"

class GameBase
{
public:
    GameBase();
    virtual void Initialize(const char *title, unsigned positionX, unsigned positionY, unsigned width, unsigned height, SDL_WindowFlags windowFlags, SDL_RendererFlags rendererFlags);
    virtual void LoadContent();
    virtual void UnLoadContent();
    virtual void InputHandle();
    virtual void Update(GameTime *gameTime);
    virtual void Draw(GameTime *gameTime);
    virtual void Clean();
    virtual void SetFps(long fps);
    void Run();
    void Run(GameTime *GameTime);

protected:
    bool _isRunning = true;
    GameBase *_game = nullptr;
    SDL_Renderer *_renderer;
    SDL_Window *_window;
    long _fps = 60;
    long _previusTick = 0L;
    TimeSpan _acumulatedElapseTicks;
    DeviceGraphicManager *_deviceManager;
    TimeSpan frameDelay = TimeSpan(1000L / _fps);

};

#endif