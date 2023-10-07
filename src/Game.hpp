#pragma once

#include "Window.hpp"
#include "RendererAdapter.hpp"
#include "Circle.hpp"
#include "Rect.hpp"
#include "Mouse.hpp"

struct Game
{
public:
    Game();
    ~Game();
    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;

    void update();
    void render();
    void run();

private:
    Window _window;
    RendererAdapter _renderer;
    Mouse _mouse;
    bool _quit = false;

    // User vars
    Rect _rect;
    Circle _circle;
};