#include "RendererAdapter.hpp"

RendererAdapter::RendererAdapter(Window &window)
    : _renderer(SDL_CreateRenderer(&window.get_underlying_window(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer)
{
    if (!_renderer)
    {
        SDL_Quit();
        util::panic("Failed to create renderer");
    }
}

void RendererAdapter::clear_frame(Colors color) const
{
    set_color(color);
    SDL_RenderClear(_renderer.get());
}

void RendererAdapter::present_frame() const
{
    SDL_RenderPresent(_renderer.get());
}

void RendererAdapter::render_rect(const Rect &rect) const
{
    set_color(rect.get_color());
    SDL_Rect sdl_rect = to_sdl_rect(rect);
    SDL_RenderFillRect(_renderer.get(), &sdl_rect);
}

void RendererAdapter::render_circle(const Circle &circle) const
{
    set_color(circle.color);
    SDL2Helpers::SDL_RenderFillCircle(_renderer.get(), circle.pos.x, circle.pos.y, circle.radius);
}

void RendererAdapter::set_color(Colors color) const
{
    const auto &[r, g, b, a] = SDL2Helpers::to_sdl_color(color);
    SDL_SetRenderDrawColor(_renderer.get(), r, g, b, a);
}