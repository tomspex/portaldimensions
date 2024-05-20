#ifndef ENTITY_H
#define ENTITY_H

#include "component.h"

typedef struct {
    Sprites   *sprites;
    Collision *collision;
    Transform *transform;
    Velocity  *velocity;
    Stats     *stats;
} Entity;

void e_CreateSprites(Entity *entity);
void e_CreateCollision(Entity *entity);
void e_CreateTransform(Entity *entity);
void e_CreateVelocity(Entity *entity);
void e_CreateStats(Entity *entity);
void e_DestroyEntity(Entity *entity);
void e_DrawEntity(Entity *entity, SDL_Renderer *renderer);

#endif//ENTITY_H
