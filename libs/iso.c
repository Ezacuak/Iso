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