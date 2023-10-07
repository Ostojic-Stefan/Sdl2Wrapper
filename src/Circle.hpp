#pragma once

#include "Vec2.hpp"
#include "Color.hpp"

struct Circle
{
    Circle(const Vec2 &pos, int radius, Colors color);

    Vec2 pos;
    int radius;
    Colors color;
};
