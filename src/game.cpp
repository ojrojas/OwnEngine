#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "includes/game.hpp"
#include "includes/devicemanager.hpp"
#include "includes/texturemanager.hpp"

DeviceManager *deviceManager = nullptr;
SDL_Texture *player = nullptr;
SDL_Rect srcRect, destRect;
TextureManager *textureManager = TextureManager::Instance();

Game::Game()
{
    _game = this;
}

void Game::Initialize(const char *title, unsigned positionX, unsigned positionY, unsigned width, unsigned height, SDL_WindowFlags windowFlags, SDL_RendererFlags rendererFlags)
{
    deviceManager = new DeviceManager();
    deviceManager->_title ="New WindowName Renderer";
    deviceManager->_width = 1920;
    deviceManager->_height = 1080;
    deviceManager->_windowFlags = SDL_WINDOW_RESIZABLE;
    deviceManager->ApplyChanges();
    _renderer = deviceManager->_renderer;
    _window = deviceManager->_window;
}

void Game::LoadContent()
{
    textureManager->Load("assets/player.png", "player", _renderer, IMG_INIT_PNG);
}

void Game::UnLoadContent()
{
}

void Game::InputHandle()
{
    SDL_Event event;

    // (1) Handle Input
    // Start our event loop
    while (SDL_PollEvent(&event))
    {
        // Handle each specific event
        if (event.type == SDL_QUIT)
        {
            _isRunning = false;
        }
    }
}
void Game::Update(GameTime *gameTime)
{
    counter++;
    destRect.h = 64;
    destRect.w = 64;
    destRect.x = counter;

    std::cout << "rate fps: " << gameTime->GetTotalGameTime().GetValue() << std::endl;
}

void Game::Draw(GameTime *gameTime)
{
    SDL_RenderClear(_renderer);
    textureManager->Draw("player", counter, 0, 60, 60, _renderer);
    // SDL_RenderCopy(_renderer, player, NULL, &destRect);
    SDL_RenderPresent(_renderer);
}

void Game::Clean()
{
    SDL_RenderClear(_renderer);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    delete deviceManager;
    SDL_Quit();
    std::cout << "All things destroyed and cleaning" << std::endl;
}

void Game::Run()
{
    GameTime *gameTime = new GameTime();
    Run(gameTime);
}

void Game::Run(GameTime *gameTime)
{
    TimeSpan frameDelay = TimeSpan(1000 / _fps);

    while (_isRunning)
    {
        gameTime->SetElapseGameTime(SDL_GetTicks());
        InputHandle();
        Update(gameTime);
        Draw(gameTime);
        gameTime->SetTotalGameTime(SDL_GetTicks() - gameTime->GetElapseGameTime().GetValue());

        if (frameDelay.GetValue() > gameTime->GetTotalGameTime().GetValue())
        {
            SDL_Delay(frameDelay.GetValue() - gameTime->GetTotalGameTime().GetValue());
        }
    }
}
