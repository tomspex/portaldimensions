#ifndef COMPONENT_H
#define COMPONENT_H

#include <stdbool.h>
#include <SDL2/SDL.h>

#include "var.h"

#define Collision SDL_Rect
#define Velocity vec2

typedef struct {
    SDL_Texture *spritesheet;
    SDL_RendererFlip flip;
    SDL_Rect src;
    SDL_Rect dest;
} Sprites;

typedef struct {
    vec2 position; 
    vec2 scale;
    float rotation;
} Transform;

typedef struct {
    int health,
        speed;
} Stats;

#endif//COMPONENT_H
