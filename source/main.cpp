#include <math.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "vector2d.h"
#include "perl.h"

int main()
{
    int w = 1000, h = 1000;
    SDL_Window* wind;
    SDL_Renderer* rend;
    SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_SHOWN, &wind, &rend);
    SDL_Event e;
    bool end = false;
    vector2d d(1, 1);
    while (!end)
    {
        while (SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
                end = true;
        }
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);
        SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
        vector2d p = polarCor(prelin(polarCor(0.9, 0) + d) * 255 + 255, 0);
        for(double a = 0; a < 2*M_PI; a += 0.01)
        {
            vector2d n = polarCor(prelin(polarCor(0.9, a) + d) * 255 + 255, a);
            SDL_RenderDrawLine(rend, n.x + w/2, n.y + h/2, p.x + w/2, p.y + h/2);
            p = n;
        }
        SDL_RenderPresent(rend);
        d += vector2d(1, 1);
        SDL_Delay(500);
    }
}