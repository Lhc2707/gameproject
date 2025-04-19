#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>

const int TILE_SIZE = 32;
const int MAP_WIDTH = 100;  // số ô ngang
const int MAP_HEIGHT = 20;  // số ô dọc

class Map {
public:
    Map(SDL_Renderer* renderer);
    ~Map();

    void render(SDL_Renderer* renderer, int cameraX);

private:
    int tiles[MAP_HEIGHT][MAP_WIDTH];
    SDL_Texture* tileTexture;
};

#endif
