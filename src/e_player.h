#ifndef PLAYER_H
#define PLAYER_H

#include "var.h"
#include "e_entity.h"

#define E_PLAYER_SPEED 2
#define E_PLAYER_WIDTH 32
#define E_PLAYER_HEIGHT 32

E_Entity E_PlayerCreate(SDL_Renderer *renderer);
void E_PlayerInput(E_Entity *player);

#endif//PLAYER_H
