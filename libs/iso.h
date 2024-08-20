#ifndef ISO_H
#define ISO_H

#include <SDL2/SDL.h>
#include <stdio.h>

#define WORLD_HEIGHT 20
#define WORLD_WIDTH 20


/*********************************/
/*                               */
/*    Structure pour le jeu      */
/*                               */
/*********************************/
typedef struct {
    int tx, ty;
} Texture;

typedef struct {
    Texture texture;
    int x, y, z;
} Tile;

typedef struct {
    Tile tiles[WORLD_WIDTH][WORLD_HEIGHT];
} World;

/*********************************/
/*                               */
/*   Structure pour la logique   */
/*                               */
/*********************************/

typedef struct {
    int mx, my;
} Map;

typedef struct {
    int sx, sy;
} Screen;

/*********************************/
/*                               */
/*        Drawing Function       */ 
/*                               */
/*********************************/

SDL_Texture* ISO_LoadSheet(const char path[], SDL_Renderer* renderer);

void ISO_DrawWorld(SDL_Renderer* renderer, World world);

#endif