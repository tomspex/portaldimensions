#include "e_active.h"

void E_MoveAndCollide(E_Entity *entity) {
    entity->transform->position.x += entity->velocity->x * entity->stats->speed;
    entity->transform->position.y += entity->velocity->y * entity->stats->speed;
    if(entity->sprites) {
        entity->sprites->dest.x = round(entity->transform->position.x);
        entity->sprites->dest.y = round(entity->transform->position.y);
    }
    // add collide part later
}
