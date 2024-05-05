#ifndef PLAYER_H
#define PLAYER_H

#include "var.h"
#include "e_entity.h"

#define E_PLAYER_SPEED 5
#define E_PLAYER_WIDTH 32
#define E_PLAYER_HEIGHT 32

E_Entity E_PlayerCreate(SDL_Renderer *renderer);
vec2 E_PlayerInput(E_Entity *player);

#endif//PLAYER_H
