#pragma once

#include "Vec2.hpp"

#include <cstdint>
#include <SDL.h>

enum class MouseButton
{
    Left = SDL_BUTTON_LMASK,
    Right = SDL_BUTTON_RMASK,
    Middle = SDL_BUTTON_MIDDLE
};

struct Mouse
{
public:
    bool button_down(MouseButton btn) const;
    bool button_pressed(MouseButton btn) const;
    bool button_released(MouseButton btn) const;

    void update();

private:
    std::uint32_t _mouseState = 0u;
    std::uint32_t _prevMouseState = 0u;
    Vec2 _position;
};