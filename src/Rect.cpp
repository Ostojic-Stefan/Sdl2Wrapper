#include "Rect.hpp"

Rect::Rect(const Vec2 &top_left, int w, int h)
    : _top_left(top_left), _width(w), _height(h) {}

Rect::Rect(const Vec2 &top_left, int w, int h, Colors color)
    : Rect(top_left, w, h)
{
    _color = color;
}

Rect::Rect(const Vec2 &top_left, const Vec2 &bottom_right)
    : _top_left(top_left)
{
    Vec2 diff = bottom_right - top_left;
    _width = diff.x;
    _height = diff.y;
}

const Vec2 &Rect::get_pos() const
{
    return _top_left;
}

int Rect::get_width() const
{
    return _width;
}

int Rect::get_height() const
{
    return _height;
}

void Rect::set_color(Colors color)
{
    _color = color;
}

Colors Rect::get_color() const
{
    return _color;
}

SDL_Rect to_sdl_rect(const Rect &rect)
{
    return {
        rect._top_left.x, rect._top_left.y,
        rect._width, rect._height};
}
