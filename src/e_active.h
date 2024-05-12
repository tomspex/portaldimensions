#ifndef ENTITY_ACTIVE
#define ENTITY_ACTIVE

#include "var.h"
#include "e_entity.h"

#define E_DEFAULT_FRICTION 0.1

void E_MoveAndCollide(E_Entity *entity);
void E_Move(E_Entity *entity);
void E_VelocityFlip(E_Entity *entity);

#endif//ENTITY_ACTIVE
