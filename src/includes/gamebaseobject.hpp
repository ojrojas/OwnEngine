#ifndef __GAMEBASEOBJECT_H__
#define __GAMEBASEOBJECT_H__
#include <SDL.h>
#include <iostream>

class GameBaseObject
{
private:
    SDL_Texture *_texture;
    int _zIndex;
    bool _destroy = false;

public:
    GameBaseObject();
    std::function<void()> onEvent;
    void Destroy()
    {
        _destroy = true;
    }

protected:
    virtual int _width;
    virtual int height;
    virtual void Render(SDL_Renderer *renderer);
    std::vector<float> _position;
    std::string _textureId;
};

#endif /* GAMEBASEOBJECT */