#ifndef TILE_H
#define TILE_H

#include <SDL2/SDL.h>

#include "entity.h"
#include "var.h"

#define TILE_WIDTH  32
#define TILE_HEIGHT 32

typedef struct {
	int spriteID;
	ivec2 position;
} Tile;

typedef struct {
    Tile *tiles;
    int height, width, size;
    SDL_Texture *spritesheet;
} TileMap;

TileMap TileMapCreate(SDL_Texture *spritesheet);
void    TileMapRead(TileMap *tileMap, const char *src);
void    TileMapRender(TileMap *tileMap, Entity *camera, SDL_Renderer *renderer);
void    TileMapDestroy(TileMap *tileMap);

//  The tilemaps will be loaded with a datatype that is a set of integers. The first and second ints represent the height and width of the tilemap and the rest are the sprite values of each individual tile that are loaded from a spritesheet.

#endif//TILE_H
