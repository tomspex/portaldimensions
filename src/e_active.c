#include "e_active.h"

void E_MoveAndCollide(E_Entity *entity, vec2 inputdir) {
    entity->transform->position.x += inputdir.x * entity->stats->speed;
    entity->transform->position.y += inputdir.y * entity->stats->speed;
    if(entity->sprites) {
        entity->sprites->dest.x = round(entity->transform->position.x);
        entity->sprites->dest.y = round(entity->transform->position.y);
    }
    // add collide part later
}
