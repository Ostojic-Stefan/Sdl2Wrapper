#pragma once

#include <SDL.h>
#include <numbers>
#include "Color.hpp"

namespace SDL2Helpers
{
    inline SDL_Color to_sdl_color(Colors color)
    {
        std::uint32_t c = static_cast<std::uint32_t>(color);

        SDL_Color sdlColor;
        sdlColor.r = (c >> 24) & 0xFF;
        sdlColor.g = (c >> 16) & 0xFF;
        sdlColor.b = (c >> 8) & 0xFF;
        sdlColor.a = c & 0xFF;

        return sdlColor;
    }

    // https://gist.github.com/Gumichan01/332c26f6197a432db91cc4327fcabb1c
    inline int SDL_RenderDrawCircle(SDL_Renderer *renderer, int x, int y, int radius)
    {
        int offsetx, offsety, d;
        int status;

        offsetx = 0;
        offsety = radius;
        d = radius - 1;
        status = 0;

        while (offsety >= offsetx)
        {
            status += SDL_RenderDrawPoint(renderer, x + offsetx, y + offsety);
            status += SDL_RenderDrawPoint(renderer, x + offsety, y + offsetx);
            status += SDL_RenderDrawPoint(renderer, x - offsetx, y + offsety);
            status += SDL_RenderDrawPoint(renderer, x - offsety, y + offsetx);
            status += SDL_RenderDrawPoint(renderer, x + offsetx, y - offsety);
            status += SDL_RenderDrawPoint(renderer, x + offsety, y - offsetx);
            status += SDL_RenderDrawPoint(renderer, x - offsetx, y - offsety);
            status += SDL_RenderDrawPoint(renderer, x - offsety, y - offsetx);

            if (status < 0)
            {
                status = -1;
                break;
            }

            if (d >= 2 * offsetx)
            {
                d -= 2 * offsetx + 1;
                offsetx += 1;
            }
            else if (d < 2 * (radius - offsety))
            {
                d += 2 * offsety - 1;
                offsety -= 1;
            }
            else
            {
                d += 2 * (offsety - offsetx - 1);
                offsety -= 1;
                offsetx += 1;
            }
        }

        return status;
    }
    inline int SDL_RenderFillCircle(SDL_Renderer *renderer, int x, int y, int radius)
    {
        int offsetx, offsety, d;
        int status;

        offsetx = 0;
        offsety = radius;
        d = radius - 1;
        status = 0;

        while (offsety >= offsetx)
        {
            status += SDL_RenderDrawLine(renderer, x - offsety, y + offsetx,
                                         x + offsety, y + offsetx);
            status += SDL_RenderDrawLine(renderer, x - offsetx, y + offsety,
                                         x + offsetx, y + offsety);
            status += SDL_RenderDrawLine(renderer, x - offsetx, y - offsety,
                                         x + offsetx, y - offsety);
            status += SDL_RenderDrawLine(renderer, x - offsety, y - offsetx,
                                         x + offsety, y - offsetx);

            if (status < 0)
            {
                status = -1;
                break;
            }
            if (d >= 2 * offsetx)
            {
                d -= 2 * offsetx + 1;
                offsetx += 1;
            }
            else if (d < 2 * (radius - offsety))
            {
                d += 2 * offsety - 1;
                offsety -= 1;
            }
            else
            {
                d += 2 * (offsety - offsetx - 1);
                offsety -= 1;
                offsetx += 1;
            }
        }

        return status;
    }

} // namespace SDL2Helpers
