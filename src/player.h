#ifndef PLAYER_H
#define PLAYER_H

#include "var.h"
#include "entity.h"

Entity PlayerCreate(SDL_Renderer *renderer);
void PlayerInput(Entity *player);

#endif//PLAYER_H
