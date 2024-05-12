#ifndef COMPONENT_H
#define COMPONENT_H

#include <stdbool.h>
#include <SDL2/SDL.h>

#include "var.h"

#define C_Collision SDL_Rect
#define C_Velocity vec2

typedef struct {
    SDL_Texture *spritesheet;
    SDL_RendererFlip flip;
    SDL_Rect src;
    SDL_Rect dest;
} C_Sprites;

typedef struct {
    vec2 position; 
    vec2 scale;
    float rotation;
} C_Transform;

typedef struct {
    int health,
        speed;
} C_Stats;

#endif//COMPONENT_H
