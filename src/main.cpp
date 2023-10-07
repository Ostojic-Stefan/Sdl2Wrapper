#include "util.hpp"
#include "Vec2.hpp"
#include "Rect.hpp"
#include "Color.hpp"
#include "RendererAdapter.hpp"
#include "Window.hpp"
#include <SDL.h>
#include <memory>

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        util::panic("SDL Initialization failed");

    Window window("Pong", 800, 600);
    RendererAdapter renderer(window);

    Rect rect({100, 100}, 100, 100, Colors::Yellow);
    Circle circle({200, 200}, 30, Colors::White);

    bool quit = false;

    window.submit_event_callback([&quit](const SDL_Event &ev) mutable
                                 { if (ev.key.keysym.sym == SDLK_ESCAPE) quit = true; });
    window.submit_event_callback([&quit](const SDL_Event &ev) mutable
                                 { if (ev.type == SDL_QUIT) quit = true; });

    while (!quit)
    {
        window.process_events();

        renderer.clear_frame(Colors::Cyan);

        renderer.render_rect(rect);
        renderer.render_circle(circle);

        renderer.present_frame();
    }

    SDL_Quit();

    return 0;
}