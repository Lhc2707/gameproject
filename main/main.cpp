#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"
#include "logic.h"
#include "map.h"
using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

struct Box {
    int x, y;
    int sz = 10;
    void render(SDL_Renderer* render){
        SDL_Rect filled_rect;
        filled_rect.x = x;
        filled_rect.y = y;
        filled_rect.w = 10;
        filled_rect.h = 10;
        SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
        SDL_RenderFillRect(render, &filled_rect);
    }

    bool insite(int x, int y)
    {
        return (0 <= x && x + sz <= 800 && 0 <= y && y + sz <= 600);
    }
};

int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();
    Box box;
    int x = 200, y = 200;

    SDL_Event e;

    while(box.insite(box.x, box.y)){
        SDL_SetRenderDrawColor(graphics.renderer, 255, 255, 255, 255);
        SDL_RenderClear(graphics.renderer);
        SDL_Texture* Marco = graphics.loadTexture("marco.png");
        graphics.renderTexture(Marco, x, y);
        SDL_RenderPresent(graphics.renderer);
        SDL_Delay(1);

        if (SDL_WaitEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) break;
        if (e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym){
                case SDLK_ESCAPE: break;
                case SDLK_RIGHT: x += 30; break;
                case SDLK_LEFT: x -= 30; break;
                case SDLK_UP: y -= 30; break;
                case SDLK_DOWN: y += 30; break;

            }
        }
    }

    waitUntilKeyPressed();
    return 0;
}
