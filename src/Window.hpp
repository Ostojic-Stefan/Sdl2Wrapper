#pragma once

#include <memory>
#include <string_view>
#include <functional>
#include <algorithm>
#include <vector>

#include "util.hpp"
#include <SDL.h>

struct Window
{
public:
    Window(std::string_view title, int width = SCREEN_WIDTH, int height = SCREEN_HEIGHT);
    void submit_event_callback(const std::function<void(const SDL_Event &)> &func);
    void process_events() const;
    SDL_Window &get_underlying_window();

private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window;
    std::vector<std::function<void(const SDL_Event &)>> _event_callbacks;

    static constexpr std::uint32_t SCREEN_WIDTH = 800;
    static constexpr std::uint32_t SCREEN_HEIGHT = 600;
};