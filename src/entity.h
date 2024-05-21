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

void CreateSprites(Entity *entity);
void CreateCollision(Entity *entity);
void CreateTransform(Entity *entity);
void CreateVelocity(Entity *entity);
void CreateStats(Entity *entity);
void EntityDestroy(Entity *entity);
void EntityRender(Entity *entity, Entity *camera, SDL_Renderer *renderer);

#endif//ENTITY_H
