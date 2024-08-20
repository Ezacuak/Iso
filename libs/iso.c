#include "iso.h"

SDL_Texture* ISO_LoadSheet(const char path[], SDL_Renderer* renderer) {
    SDL_Surface* tmp = NULL;
    SDL_Texture* spritesheet = NULL;

    tmp = SDL_LoadBMP(path);

    if (tmp == NULL) {
        fprintf(stderr, "Erreur SDL_LoadBMP : %s\n", SDL_GetError());
        return NULL;
    }
    spritesheet = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);

    if(NULL == spritesheet) {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s\n", SDL_GetError());
        return NULL;
    }
    return spritesheet;

}

World ISO_GenWorldflat(Tile tile) {
   World world;
    for (int x = 0; x < WORLD_HEIGHT; x++) {
        for (int y = 0; y < WORLD_WIDTH; y++) {
            world.tiles[x][y] = tile;
        }
    }
    return world;
}