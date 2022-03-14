#include <math.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "vector2d.h"
#include "perl.h"

int main()
{
    int w = 100, h = 100;
    SDL_Window* wind;
    SDL_Renderer* rend;
    SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_SHOWN, &wind, &rend);
    SDL_Event e;
    bool end = false;
    vector2d offset(w/2, h/2);

    while (!end)
    {
        while (SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
                end = true;
        }
        for(int x = 0; x < w; x++)
        for(int y = 0; y < w; y++)
        {
            std::cerr << prelin(vector2d(x, y)) << '\n';
            int c = prelin(vector2d(x + 0.5, y + 0.5)) * 255;
            SDL_SetRenderDrawColor(rend, c, c, c, 255);
            SDL_RenderDrawPoint(rend, x, y);
        }
        SDL_RenderPresent(rend);
    }
}