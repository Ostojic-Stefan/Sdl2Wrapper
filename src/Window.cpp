#include "Window.hpp"

Window::Window(std::string_view title, int width, int height)
    : _window(SDL_CreateWindow(title.data(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0), SDL_DestroyWindow)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Quit();
        util::panic("SDL Initialization failed");
    }

    if (!_window)
    {
        SDL_Quit();
        util::panic("Window creation failed");
    }
}

void Window::submit_event_callback(const std::function<void(const SDL_Event &)> &func)
{
    _event_callbacks.push_back(std::move(func));
}

void Window::process_events() const
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        std::for_each(_event_callbacks.begin(), _event_callbacks.end(), [&event](auto &func)
                      { func(event); });
    }
}

SDL_Window &Window::get_underlying_window()
{
    return *_window;
}
