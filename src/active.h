#ifndef ENTITY_ACTIVE
#define ENTITY_ACTIVE

#include "var.h"
#include "entity.h"

#define DEFAULT_FRICTION 0.1
#define ACTIVE_SPEED 2
#define ACTIVE_WIDTH 32
#define ACTIVE_HEIGHT 32

Entity ActiveCreate(char *spritesheet, SDL_Renderer *renderer);
void MoveAndCollide(Entity *entity);
void Move(Entity *entity);
void VelocityFlip(Entity *entity);

#endif//ENTITY_ACTIVE
