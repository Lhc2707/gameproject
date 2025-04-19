#include "Map.h"
#include <SDL2/SDL_image.h>

Map::Map(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("assets/ms4_tileset.png");
    tileTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    // Tạo map đơn giản (dòng dưới cùng là đất)
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            tiles[y][x] = (y == MAP_HEIGHT - 1) ? 1 : 0;
        }
    }
}

Map::~Map() {
    SDL_DestroyTexture(tileTexture);
}

void Map::render(SDL_Renderer* renderer, int cameraX) {
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            int tileID = tiles[y][x];
            if (tileID == 0) continue;

            SDL_Rect srcRect = { (tileID - 1) * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE };
            SDL_Rect destRect = { x * TILE_SIZE - cameraX, y * TILE_SIZE, TILE_SIZE, TILE_SIZE };
            SDL_RenderCopy(renderer, tileTexture, &srcRect, &destRect);
        }
    }
}
