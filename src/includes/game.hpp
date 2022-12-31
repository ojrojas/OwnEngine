#ifndef __Game_H__
#define __Game_H__
#include <iostream>
#include "gametime.hpp"
#include "devicemanager.hpp"

class Game
{
public:
    Game();
    virtual void Initialize(const char *title, unsigned positionX, unsigned positionY, unsigned width, unsigned height, SDL_WindowFlags windowFlags, SDL_RendererFlags rendererFlags);
    virtual void LoadContent();
    virtual void UnLoadContent();
    virtual void InputHandle();
    virtual void Update(GameTime *gameTime);
    virtual void Draw(GameTime *gameTime);
    virtual void Clean();
    void SetFps(long fps);
    void Run();
    void Run(GameTime *GameTime);

private:
    bool _isRunning = true;
    Game *_game = nullptr;
    SDL_Renderer *_renderer;
    SDL_Window *_window;
    long _fps = 60;
    int counter = 0;
};

#endif