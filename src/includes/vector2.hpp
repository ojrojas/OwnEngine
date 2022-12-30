#ifndef __VECTOR2_H__
#define __VECTOR2_H__

#include <iostream>
#include <math.h>

class Vector2
{
public:
    Vector2(float x, float y) : _x(x), _y(y) {}

    float GetX() { return _x; }
    float GetY() { return _y; }

    void SetX(float x) { _x = x; }
    void SetY(float y) { _y = y; }

private:
    float _x;
    float _y;
};

#endif /* __VECTOR2_H__ */