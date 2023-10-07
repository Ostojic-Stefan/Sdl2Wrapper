#include "Mouse.hpp"

bool Mouse::button_down(MouseButton btn) const
{
    return static_cast<std::uint32_t>(btn) & _mouseState;
}

bool Mouse::button_pressed(MouseButton btn) const
{
    return !(_prevMouseState & static_cast<std::uint32_t>(btn)) &&
           _mouseState & static_cast<std::uint32_t>(btn);
}

bool Mouse::button_released(MouseButton btn) const
{

    return _prevMouseState & static_cast<std::uint32_t>(btn) &&
           !(_mouseState & static_cast<std::uint32_t>(btn));
}

void Mouse::update()
{
    _prevMouseState = _mouseState;
    _mouseState = SDL_GetMouseState(&_position.x, &_position.y);
}
