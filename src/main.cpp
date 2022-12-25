#include <iostream>
#include <SDL2/SDL.h>
#include "includes/game.hpp"


int main(int argc, char *argv[])
{
    Game* game = nullptr;
    game = new Game("chapter one",SDL_RENDERER_ACCELERATED,  SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 640,480);
    game->Initialize();

    long gameTimeValue = 0L;
    GameTime* gameTime = new GameTime();

    
    while(game->Running())
    {
        game->HandleEvents();
        game->Update(*gameTime);
        game->Render(*gameTime);
    }

    game->Clean();
    return 0;
}
