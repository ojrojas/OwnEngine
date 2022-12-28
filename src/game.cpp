#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "includes/game.hpp"
#include "includes/devicemanager.hpp"
#include "includes/texturemanager.hpp"

DeviceManager *deviceManager = nullptr;
SDL_Texture *player = nullptr;
SDL_Rect srcRect, destRect;
TextureManager* texturePlayer = TextureManager::Instance();

Game::Game()
{
    _game = this;
}

void Game::Initialize(const char *title, unsigned positionX, unsigned positionY, unsigned width, unsigned height, SDL_WindowFlags windowFlags, SDL_RendererFlags rendererFlags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL_Init successfull " << std::endl;
        _window = SDL_CreateWindow(title, positionX, positionY, width, height, windowFlags);

        if (_window)
        {
            _renderer = SDL_CreateRenderer(_window, 0, rendererFlags);

            if (_renderer)
            {
                SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 50);

                // SDL_Surface *tempSurface = IMG_Load("assets/player.png");
                texturePlayer->Load("assets/player.png","player",_renderer,IMG_INIT_PNG);
                // player = SDL_CreateTextureFromSurface(_renderer, tempSurface);
                // SDL_FreeSurface(tempSurface);
            }
            else
            {
                std::cout << "Renderer could not be created: " << SDL_GetError() << std::endl;
            }
        }
        else
        {
            std::cout << "Window could not be created: " << SDL_GetError() << std::endl;
        }
    }
    else
    {
        std::cout << "SDL could not be initialized: " << SDL_GetError() << std::endl;
    }
}

void Game::LoadContent()
{
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
    texturePlayer->Draw("player",counter,0,60,60,_renderer);
   // SDL_RenderCopy(_renderer, player, NULL, &destRect);
    SDL_RenderPresent(_renderer);
}

void Game::Clean()
{
    SDL_RenderClear(_renderer);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
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
