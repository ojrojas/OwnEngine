#include <iostream>
#include <SDL.h>
#include "game.cpp"

Game *game = nullptr;

int main(int argc, char *argv[])
{
  
    game = new Game();
    game->Initialize("remainWindows", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 260, 240, SDL_WINDOW_RESIZABLE, SDL_RENDERER_ACCELERATED);
    game->SetFps(120L);
    game->LoadContent();
    game->Run();
    game->Clean();
    return 0;
}