#ifndef PLAYER_H
#define PLAYER_H

#include "var.h"
#include "entity.h"

#define PLAYER_SPEED 2
#define PLAYER_WIDTH 32
#define PLAYER_HEIGHT 32

Entity PlayerCreate(SDL_Renderer *renderer);
void PlayerInput(Entity *player);

#endif//PLAYER_H
