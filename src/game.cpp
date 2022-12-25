#include "includes/game.hpp"
#include "includes/texturemanager.hpp"
#include <iostream>
#include "includes/devicemanager.hpp"

DeviceManager *deviceManager;
TextureManager *_textureInstance;

void Game::Initialize() {}

Game::Game(const char *title, SDL_RendererFlags flag, const unsigned int xPosition, const unsigned int yPosition, const int width, const int height)
{
    deviceManager = new DeviceManager();
    deviceManager->SetPositionX(xPosition);
    deviceManager->SetPositionY(yPosition);
    deviceManager->SetWidthDevice(width);
    deviceManager->SetHeightDevice(height);
    _height = height;
    _width = width;
    _positionX = xPosition;
    _positionY = yPosition;
    _renderer = deviceManager->GetRenderer(flag);
    _textureInstance = TextureManager::Instance();
    _running = true;
}

void Game::Render(GameTime gameTime)
{
    if (!_textureInstance->Load("assets/mario.jpeg", "empty", _renderer, IMG_INIT_JPG))
    {
        std::cout << "The render texture do not initialized";
    }

    _textureInstance->Draw("empty", _positionX, _positionY, _width, _height, _renderer);
    SDL_RenderPresent(_renderer);
}

void Game::Update(GameTime gameTime) {}

void Game::HandleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            _running = false;
            break;
        default:
            break;
        }
    }
}
void Game::Clean()
{
    std::cout << "Cleaning game components";
    deviceManager->CleanDevice();
    delete deviceManager;
    SDL_Quit();
}

bool Game::Running() { return _running; }
