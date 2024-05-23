#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

typedef struct {
    SDL_Rect src;
    SDL_Rect collision;
} Sprite;

typedef struct {
    SDL_Texture *spritesheet;
    Sprite *sprites;
} Spritesheet;

Spritesheet SpritesheetCreate(const char *texture, const char *sprites, SDL_Renderer *renderer);
void SpritesheetDestroy(Spritesheet *spritesheet);

#endif//SPRITE_H
