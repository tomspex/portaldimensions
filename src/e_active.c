#include "e_active.h"

void E_MoveAndCollide(E_Entity *entity) {
    E_Move(entity);
    // add collide part later
}

void E_Move(E_Entity *entity) {
    entity->transform->position.x += entity->velocity->x * entity->stats->speed;
    entity->transform->position.y += entity->velocity->y * entity->stats->speed;
    if(entity->sprites) {
        entity->sprites->dest.x = round(entity->transform->position.x);
        entity->sprites->dest.y = round(entity->transform->position.y);
    }
}

void E_VelocityFlip(E_Entity *entity) {
    if(entity->velocity->x > 0) {
        entity->sprites->flip = SDL_FLIP_HORIZONTAL;
    } else {
        entity->sprites->flip = SDL_FLIP_NONE;
    }
}
