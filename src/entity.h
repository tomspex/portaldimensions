#ifndef ENTITY_H
#define ENTITY_H

#include "component.h"

typedef struct {
    C_Sprites *sprites;
    C_Collision *collision;
    C_Transform *transform;
} E_Entity;

typedef struct {
    C_Sprites *sprites;
    C_Transform *transform;
} E_GUIElement;

void MoveAndCollide(E_Entity *entity, vec2i input_dir);

#endif//ENTITY_H
