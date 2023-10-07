#pragma once

#include "Vec2.hpp"
#include "Color.hpp"
#include <SDL.h>

struct Rect
{
public:
    Rect(const Vec2 &top_left, int w, int h);
    Rect(const Vec2 &top_left, int w, int h, Colors color);
    Rect(const Vec2 &top_left, const Vec2 &bottom_right);

    const Vec2 &get_pos() const;
    int get_width() const;
    int get_height() const;

    void set_color(Colors color);
    Colors get_color() const;

    friend SDL_Rect to_sdl_rect(const Rect &rect);

private:
    Vec2 _top_left;
    int _width, _height;
    Colors _color;
};