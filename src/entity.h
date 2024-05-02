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

#endif//ENTITY_H
