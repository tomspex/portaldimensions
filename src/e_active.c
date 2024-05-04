#include "e_active.h"

void E_MoveAndCollide(E_Entity *entity, vec2 inputdir) {
    entity->transform->dest.x += inputdir.x * entity->stats->speed;
    entity->transform->dest.y += inputdir.y * entity->stats->speed;

    // add collide part later
}
