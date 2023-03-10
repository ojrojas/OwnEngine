#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "includes/game.hpp"
#include "includes/devicemanager.hpp"
#include "includes/texturemanager.hpp"

DeviceManager *deviceManager = nullptr;
SDL_Texture *player = nullptr;
TextureManager *textureManager = TextureManager::Instance();

Game::Game()
{
    _game = this;
}

void Game::Initialize(const char *title, unsigned positionX, unsigned positionY, unsigned width, unsigned height, SDL_WindowFlags windowFlags, SDL_RendererFlags rendererFlags)
{
    deviceManager = new DeviceManager();
    deviceManager->_title = "New WindowName Renderer";
    deviceManager->_windowFlags = windowFlags;
    deviceManager->_rendererFlags = rendererFlags;
    deviceManager->_width = width;
    deviceManager-> _height = height;

    deviceManager->ApplyChanges();
    _renderer = deviceManager->_renderer;
    _window = deviceManager->_window;
}

void Game::LoadContent()
{
    textureManager->Load("assets/view.png", "level1", _renderer, IMG_INIT_PNG);
    textureManager->Load("assets/smb_mario_sheet.png", "mario", _renderer, IMG_INIT_PNG);
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
    counter--;
    std::cout << "rate fps: " << gameTime->GetTotalGameTime().GetValue() << std::endl;
}

void Game::Draw(GameTime *gameTime)
{
    textureManager->BeginRender(_renderer); // most be only one
    textureManager->Draw("level1",counter,0,3584,240,_renderer);
    textureManager->DrawFrame("mario", _renderer, {300, 0, 30, 16}, {x : 80, y : 192, w : 32, h : 16});
    textureManager->FinishRender(_renderer); // most be only one
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

void Game::SetFps(long fps)
{
    _fps = fps;
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
