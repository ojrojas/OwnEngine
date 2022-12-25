#ifndef __Game_H__
#define __Game_H__
#include <SDL2/SDL.h>
#include <iostream>
#include "gametime.hpp"

class Game
{
public:
    Game(
        const char *title,
        SDL_RendererFlags flag,
        const unsigned int xPosition = 0,
        const unsigned int yPosition = 0,
        const int width = 640,
        const int height = 480);
    ~Game() {}

    void Initialize();
    bool Running();
    void Render(GameTime gameTime);
    void Update(GameTime gameTime);
    void HandleEvents();
    void Clean();
    void Draw(std::string id, int x, int y, int width, int height, SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
    bool _running;
    int _height;
    int _width;
    int _positionX;
    int _positionY;
    GameTime _gameTime;
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    SDL_Texture *_texture;
    SDL_Rect _sourceRectangle;
    SDL_Rect _destinationRectangle;
};

#endif