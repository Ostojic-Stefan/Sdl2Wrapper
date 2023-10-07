#include "Game.hpp"

Game::Game() : _window("Pong"), _renderer(_window),
               _rect({100, 100}, 100, 100, Colors::Yellow),
               _circle({200, 200}, 30, Colors::White)

{
    _window.submit_event_callback([this](const SDL_Event &ev)
                                  { if (ev.key.keysym.sym == SDLK_ESCAPE) _quit = true; });
    _window.submit_event_callback([this](const SDL_Event &ev)
                                  { if (ev.type == SDL_QUIT) _quit = true; });
}

Game::~Game()
{
    SDL_Quit();
}

void Game::render()
{
    _renderer.render_rect(_rect);
    _renderer.render_circle(_circle);
}

void Game::update()
{
    _window.process_events();
    _mouse.update();

    if (_mouse.button_pressed(MouseButton::Middle))
        std::cout << "Middle Pressed\n";

    if (_mouse.button_released(MouseButton::Middle))
        std::cout << "Middle Released\n";
}

void Game::run()
{
    while (!_quit)
    {
        _renderer.clear_frame(Colors::Cyan);
        update();
        render();
        _renderer.present_frame();
    }
}
