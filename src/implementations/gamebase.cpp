#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "../includes/gamebase.hpp"
#include "../includes/devicegraphicmanager.hpp"

GameBase::GameBase()
{
    _game = this;
    _deviceManager = new DeviceGraphicManager();
}

void GameBase::Initialize(const char *title, unsigned positionX, unsigned positionY, unsigned width, unsigned height, Uint32 windowFlags, SDL_RendererFlags rendererFlags)
{
    _deviceManager->_title = "New WindowName Renderer";
    _deviceManager->_windowFlags = windowFlags;
    _deviceManager->_rendererFlags = rendererFlags;
    _deviceManager->_width = width;
    _deviceManager-> _height = height;

    _deviceManager->ApplyChanges();
    _renderer = _deviceManager->_renderer;
    _window = _deviceManager->_window;
}

void GameBase::LoadContent()
{
}

void GameBase::UnLoadContent()
{
}

void GameBase::InputHandle()
{
    
}
void GameBase::Update(GameTime *gameTime)
{
}

void GameBase::Draw(GameTime *gameTime)
{
}

void GameBase::Clean()
{
    SDL_RenderClear(_renderer);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    delete _deviceManager;
    SDL_Quit();
    std::cout << "All things destroyed and cleaning" << std::endl;
}

void GameBase::SetFps(long fps)
{
    _fps = fps;
}

void GameBase::Run()
{
    GameTime *gameTime = new GameTime();
    Run(gameTime);
}

void GameBase::Run(GameTime *gameTime)
{

    while (_isRunning)
    {
        gameTime->SetElapseGameTime(SDL_GetTicks());
        InputHandle();
        Update(gameTime);
        Draw(gameTime);
        gameTime->SetTotalGameTime(SDL_GetTicks() - gameTime->GetElapseGameTime().GetValue());

        if (frameDelay.GetValue() > gameTime->GetTotalGameTime().GetValue())
        {
            long frameDelayFromFps = frameDelay.GetValue() - gameTime->GetTotalGameTime().GetValue();
            std::cout << "rate fps: " << gameTime->GetTotalGameTime().GetValue() * _fps << std::endl;
            SDL_Delay(frameDelayFromFps);
        }
    }
}
