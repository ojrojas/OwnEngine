#ifndef __GAMEBASEOBJECT_H__
#define __GAMEBASEOBJECT_H__

#include <iostream>
#include <SDL.h>
#include "vector2.hpp"

class GameBaseObject
{
private:
    SDL_Texture *_texture;
    int _zIndex;

public:
    GameBaseObject();
    std::function<void()> onEvent;

protected:
    virtual int _width;
    virtual int height;
    Vector2 _position;
    virtual void Render(SDL_Renderer *renderer);
    std::vector<int> _position;

    std::string _textureId;
};

#endif /* GAMEBASEOBJECT */