#ifndef ENTITY_ACTIVE
#define ENTITY_ACTIVE

#include "var.h"
#include "entity.h"

#define DEFAULT_FRICTION 0.1

void MoveAndCollide(Entity *entity);
void Move(Entity *entity);
void VelocityFlip(Entity *entity);

#endif//ENTITY_ACTIVE
