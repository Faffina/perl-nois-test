#include <math.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "vector2d.h"

int main()
{
    SDL_Window* wind;
    SDL_Renderer* rend;
    SDL_CreateWindowAndRenderer(1000, 1000, SDL_WINDOW_SHOWN, &wind, &rend);
    SDL_Event e;
    bool end = false;

    while (!end)
    {
        while (SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
                end = true;
        }
        for(int x = 0; x < 1000; x++)
        for(int y = 0; y < 1000; y++)
        {
            float c = 255;
            SDL_SetRenderDrawColor(rend, c, c, c, 255);
            SDL_RenderDrawPoint(rend, x, y);
        }
        SDL_RenderPresent(rend);
    }
}