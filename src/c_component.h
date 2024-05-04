#ifndef COMPONENT_H
#define COMPONENT_H

#include <SDL2/SDL.h>

#include "var.h"

#define C_Collision SDL_Rect

typedef struct {
    SDL_Texture *spritesheet;
    SDL_Rect src;
} C_Sprites;

typedef struct {
    SDL_Rect dest;
    vec2 scale;
    float rotation;
} C_Transform;

typedef struct {
    int health,
        speed;
} C_Stats;

#endif//COMPONENT_H
