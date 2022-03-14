#include <math.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "vector2d.h"

int main()
{
    int w = 1000, h = 1000;
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
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);
        SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
        for(int i = 0; i < 10; i++)
        {
            vector2d a = randUnit(i);
            a += offset;
            SDL_RenderDrawLine(rend, offset.x, offset.y, a.x, a.y);
        }

        SDL_RenderPresent(rend);
    }
}