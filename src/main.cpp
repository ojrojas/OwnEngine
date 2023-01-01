#include <iostream>
#include <SDL2/SDL.h>
#include "includes/game.hpp"

Game *game = nullptr;

int main(int argc, char *argv[])
{
    game = new Game();
    game->Initialize("remainWindows", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 260, 240, SDL_WINDOW_OPENGL, SDL_RENDERER_ACCELERATED);
    game->SetFps(120L);
    game->LoadContent();
    game->Run();
    game->Clean();
    return 0;
}