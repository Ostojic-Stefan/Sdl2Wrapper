#pragma once

#include "util.hpp"
#include "Vec2.hpp"
#include "Rect.hpp"
#include "Circle.hpp"
#include "Color.hpp"
#include "SDL2Helpers.hpp"
#include "Window.hpp"
#include <SDL.h>
#include <memory>

struct RendererAdapter
{
public:
    RendererAdapter(Window &window);
    void clear_frame(Colors color) const;
    void present_frame() const;
    void render_rect(const Rect &rect) const;
    void render_circle(const Circle &circle) const;

private:
    void set_color(Colors color) const;

private:
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> _renderer;
};
