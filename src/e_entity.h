#ifndef ENTITY_H
#define ENTITY_H

#include "c_component.h"

typedef struct {
    C_Sprites   *sprites;
    C_Collision *collision;
    C_Transform *transform;
    C_Stats     *stats;
} E_Entity;

void E_CreateSprites(E_Entity *entity);
void E_CreateCollision(E_Entity *entity);
void E_CreateTransform(E_Entity *entity);
void E_CreateStats(E_Entity *entity);
void E_DestroyEntity(E_Entity *entity);
void E_DrawEntity(E_Entity *entity, SDL_Renderer *renderer);

#endif//ENTITY_H
